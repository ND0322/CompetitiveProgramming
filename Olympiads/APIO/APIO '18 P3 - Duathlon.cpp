#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

//split into BCCs and do complementary counting
//straight up counting good pairs is too much math for me


const int MAXN = 2e5+5;
const int MAXD = 19;


int n,m,q, disc[MAXN], low[MAXN], t, cnt;

long long sz[MAXN], cur;

long long ans;


vector<int> adj[MAXN], adjBCC[MAXN];

stack<int> st;


inline void tarjans(int node, int par){
    disc[node] = low[node] = ++t;
    cur++;
    
    st.push(node);

    for(int child : adj[node]){
        if(child == par) continue;
        if(!disc[child]){
            tarjans(child,node);
            low[node] = min(low[node], low[child]);

            if(low[child] >= disc[node]){
                cnt++;
                adjBCC[node].push_back(n+cnt);
                while(adjBCC[n+cnt].empty() || adjBCC[n+cnt].back() != child){
                    adjBCC[n+cnt].push_back(st.top());
                    st.pop();
                }
            }
        }
        else low[node] = min(low[node], disc[child]);
    }
}

void dfs(int node){
    sz[node] = (node <= n);
    //original nodes

    for(int child : adjBCC[node]){
        dfs(child);
        sz[node] += sz[child];

        //choose any part of the bcc as the midpoint 
        //choose any 2 nodes in the subtree of child to be start and end
        if(node>n) ans -= (long long)adjBCC[node].size() * sz[child] * (sz[child]-1);
    }

    //same thing here but choose from nodes not in subtree
    if(node > n) ans -= (long long)adjBCC[node].size() * (cur-sz[node]) * (cur-sz[node]-1);
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;


    while(m--){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(!disc[i]){
            cur = 0;
            tarjans(i, -1);
            //add total, number of nodes visited choose 3
            ans += cur * (cur-1) * (cur-2);
            dfs(i);
        }
    }

    cout << ans << "\n";

    
 
}