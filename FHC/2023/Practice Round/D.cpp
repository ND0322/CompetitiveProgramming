#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

//find a cycle of odd length
//2cc decomposition? 
//do the 2cc decomposition
//for each comp calculate the length of the main ring and number each node in arbitrary order around the ring
//mark main ring edges then iterate through all edges
//if we have an unmarked edge and the distance between the two endpoints is even then the component is good
//for each query we have to find the minimum distance to a special component for all nodes along the path 

const int MAXN = 3e5+5;
const int MAXB = 19;

int n,m,q, low[MAXN], disc[MAXN], jmp[MAXN][MAXB], mn[MAXN][MAXB], comp[MAXN], t, cnt, col[MAXN], dp[MAXN], depth[MAXN];

bool in[MAXN], good[MAXN];

stack<int> st;

vector<int> adj[MAXN], adj2CC[MAXN], adj2[MAXN];

vector<pair<int,int>> edges;

void tarjans(int node, int par){
    low[node] = disc[node] = ++t;

    in[node] = 1;

    st.push(node);

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
            comp[st.top()] = cnt;
            in[st.top()] = 0;
            st.pop();
        }

        comp[node] = cnt;
        in[node] = 0;
        st.pop();
        
    }

}

bool color(int node, int c){

    if(col[node]) return col[node] == c;
    col[node] = c;

    

    for(int child : adj2[node]){
        
        if(!color(child, 3-c)) return 0;
        
    }
    return 1;
}

void dfs(int node, int par){
    
    dp[node] = !good[node] * 1e9;

    for(int child : adj2CC[node]){
        if(child == par) continue;
        dfs(child, node);
        dp[node] = min(dp[node], dp[child]+1);
    }
}

void init(int node){
    for(int i = 1; i < MAXB; i++){
        jmp[node][i] = jmp[jmp[node][i-1]][i-1];
        mn[node][i] = min(mn[node][i], mn[jmp[node][i-1]][i-1]);
    }

    for(int child : adj2CC[node]){
        if(jmp[node][0] == child) continue;
        depth[child] = depth[node]+1;
        jmp[child][0] = node;
        mn[child][0] = dp[node];
    }
}

pair<int,int> lift(int node, int d){
    int ans = dp[node];

    for(int i = 0; i < MAXB; i++){
        if(d & (1<<i)){
            ans = min(ans, mn[node][i]);
            node = jmp[node][i];
        }
    }

    return {node, ans};
}

int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);
    
    int ans = lift(x, depth[x] - depth[y]).second;
    x = lift(x, depth[x] - depth[y]).first;

    if(x == y) return ans;

    for(int i = MAXB-1; i >= 0; i--){
        if(jmp[x][i] != jmp[y][i]){
            ans = min({ans, mn[x][i], mn[y][i]});
            x = jmp[x][i];
            y = jmp[y][i];
    
        }
    }

    return ans;
    
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cin >> n >> m;

        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);

            edges.push_back({x,y});
        }

        for(int i = 1; i <= n; i++){
            if(!disc[i]) tarjans(i,i);
        }
        
        for(auto [x,y] : edges){
            in[x] = 0;
            in[y] = 0;
            
            
            if(comp[x] != comp[y]){
                adj2CC[comp[x]].push_back(comp[y]);
                adj2CC[comp[y]].push_back(comp[x]);
            } 
            else{
                adj2[x].push_back(y);
                adj2[y].push_back(x);
            }
        }

        bool flag = 0;

        for(int i = 1; i <= n; i++){
            if(!col[i]){
                good[comp[i]] = !color(i, 1);
                flag = 1;
            }
        } 

        for(int i = 1; i <= n; i++) cout << i << " " << comp[i] << "\n";

        

        dfs(1, -1);

        init(1);

        cout << mn[3][0] << "\n";

        for(int i = 1; i <= cnt; i++) cout << dp[i] << "\n";

        int q; cin >> q;

        while(q--){
            int x,y; cin >> x >> y;

            if(!flag) cout << "-1\n";
            else cout << min({dp[comp[x]], dp[comp[y]], lca(comp[x],comp[y])}) << "\n";
        }       

        //cout << "Case #" << _ << ": " << ans << "\n";
    }
}