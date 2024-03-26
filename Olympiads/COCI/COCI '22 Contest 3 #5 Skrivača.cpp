#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//initial distance for some source is 0 if a[i] = i
//if some child of a node i is critical between the path from a[i] to a[child] then initial distance is 1
//bfs for shortest path
//BCC + LCA for checking the second case
//no clue if my BCC works or not


const int MAXN = 2e5+5;
const int MAXD = 19;


int n,m, disc[MAXN], low[MAXN], t, cnt, jmp[MAXN][MAXD], depth[MAXN], a[MAXN], ans[MAXN];


vector<int> adj[MAXN], adjBCC[MAXN];

stack<int> st;
queue<int> q;


inline void tarjans(int node, int par){
    disc[node] = low[node] = ++t;
    
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

inline void dfs(int node){
    for(int i = 1; i < MAXD; i++) jmp[node][i] = jmp[jmp[node][i-1]][i-1];

    for(int child : adjBCC[node]){
        if(jmp[node][0] == child) continue;

        depth[child] = depth[jmp[child][0] = node]+1;
        dfs(child);
    }
}

inline int jump(int node, int d){
    for(int i = 0; i < MAXD; i++){
        if(d & (1<<i)) node = jmp[node][i];
    }

    return node;
}

inline int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);

    x = jump(x, depth[x] - depth[y]);
    if(x == y) return x;

    for(int i = MAXD-1; i >= 0; i--){
        if(jmp[x][i] != jmp[y][i]){
            x = jmp[x][i];
            y = jmp[y][i];
        }
    }

    return jmp[x][0];
}

bool critical(int a,int b, int c){
    int x = lca(a,b);
    int y = lca(a,c);
    int z = lca(b,c);

    

    return (x==y && z == c || x==z && y == c);
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    memset(ans,-1,sizeof(ans));
    for(int i = 1; i <= n; i++) cin >> a[i];

    while(m--){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(!disc[i]) tarjans(i, -1);
    }

    for(int i = 1; i <= n+cnt; i++){
        sort(adjBCC[i].begin(), adjBCC[i].end() );
        adjBCC[i].erase(unique(adjBCC[i].begin(), adjBCC[i].end() ), adjBCC[i].end());
    }

    for(int i = 1; i <= n+cnt; i++) dfs(i);

   

    for(int i = 1; i <= n; i++){
        if(a[i] == i){
            ans[i] = 0;
            q.push(i);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int child : adj[i]){
            if(child == a[i] && ans[i] == -1){
                ans[i] = 1;
                q.push(i);
            }
            if(critical(a[i], a[child], child) && ans[i] == -1){
                //cout << i << "\n";
                ans[i] = 1;
                q.push(i); 
            }
        }
    }

    while(!q.empty()){
        int node = q.front();

        q.pop();

        for(int child : adj[node]){
            if(ans[child] == -1){
                ans[child] = ans[node]+1;
                q.push(child);
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";


    
 
}