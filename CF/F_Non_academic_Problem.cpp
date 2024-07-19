#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

#define int long long

const int MAXN = 1e5+5;


int n, m, low[MAXN], disc[MAXN], t, cnt, sz[MAXN], comp[MAXN], cur, dp[MAXN];
vector<int> adj[MAXN], adj2CC[MAXN], tree;
stack<int> st;
bool in[MAXN];

void tarjans(int node, int par){
    disc[node] = low[node] = ++t;

    cur++;

    st.push(node);
    in[node] = 1;


    for(int child : adj[node]){
        if(child == par){
            par = -1;
            continue;
        }

        if(!disc[child]){
            tarjans(child, node);
            low[node] = min(low[node], low[child]);
        }
        else if(in[child]) low[node] = min(low[node], disc[child]);
    }

    if(low[node] == disc[node]){
        cnt++;

        while(st.top() != node){
            sz[cnt]++;
            comp[st.top()] = cnt;
            in[st.top()] = 0;
            st.pop();
        }

        sz[cnt]++;
        comp[st.top()] = cnt;
        in[st.top()] = 0;
        st.pop();
    }
}

void dfs(int node, int par){
    dp[node] = sz[node];
    tree.push_back(node);
    for(int child : adj2CC[node]){
        if(child == par) continue;
        dfs(child, node);
        dp[node] += dp[child];
    }
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        while(st.size()) st.pop();

        t = 0;
        cnt = 0;

        for(int i = 1; i <= n; i++){
            adj[i].clear();
            adj2CC[i].clear();
            sz[i] = 0;
            comp[i] = 0;
            in[i] = 0;
            low[i] = 0;
            disc[i] = 0;
            dp[i] = 0;
        }

        
        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }


        

        long long tot = 0;
        for(int i = 1; i <= n; i++){
            if(!disc[i]){
                cur = 0;
                tarjans(i,i);
                tot += (cur * (cur-1)) / 2;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int child : adj[i]){
                if(comp[child] == comp[i]) continue;
                adj2CC[comp[i]].push_back(comp[child]);
                adj2CC[comp[child]].push_back(comp[i]);
            }
        }

        for(int i = 1; i <= cnt; i++){
            sort(adj2CC[i].begin(), adj2CC[i].end());
            adj2CC[i].erase(unique(adj2CC[i].begin(), adj2CC[i].end()), adj2CC[i].end());
        }

        long long ans = 0;

        

        for(int i = 1; i <= cnt; i++){
            if(!dp[i]){
                tree.clear();
                dfs(i, i);
                for(int j : tree){
                    ans = max(ans, (dp[i] - dp[j]) * dp[j]);
                }
            }
        }

        cout << tot-ans << "\n";
    }
}