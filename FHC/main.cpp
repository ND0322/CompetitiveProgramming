#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <queue>


using namespace std;

//find a cycle of odd length
//2cc decomposition? 
//do the 2cc decomposition
//for each comp calculate the length of the main ring and number each node in arbitrary order around the ring
//mark main ring edges then iterate through all edges
//if we have an unmarked edge and the distance between the two endpoints is even then the component is good
//for each query we have to find the minimum distance to a special component for all nodes along the path 

const int MAXN = 3e5+5;
const int MAXB = 20;

int n,m,q, low[MAXN], disc[MAXN], jmp[MAXN][MAXB], mn[MAXN][MAXB], comp[MAXN], t, cnt, col[MAXN], dp[MAXN], depth[MAXN], parent[MAXN], sz;

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
    sz++;

    

    for(int child : adj2[node]){
        
        if(!color(child, 3-c)) return 0;
        
    }
    return 1;
}

void bfs(){
    
    queue<int> q;
    fill(in+1, in+n+1,0);
    for(int i = 1; i <= n; i++){
        if(good[i]){
            q.push(i);
            in[i] = 1;
        }
    }

    while(q.size()){
        int node = q.front();

        q.pop();

        for(int child : adj2CC[node]){
            if(in[child]) continue;
            dp[child] = dp[node]+1;
            in[node] = 1;

            q.push(child);
        }
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
        mn[child][0] = dp[child];
        init(child);
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

    return min(dp[x],ans);
    
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cin >> n >> m;

        edges.clear();

        while(st.size()) st.pop();

        t = 0;
        cnt = 0;

        for(int i = 1; i <= n; i++){
            low[i] = 0;
            disc[i] = 0;
            adj[i].clear();
            in[i] = 0;
            dp[i] = 0;
            adj2[i].clear();
            adj2CC[i].clear();
            good[i] = 0;
            comp[i] = 0;
            col[i] = 0;
            depth[i] = 0;

            for(int j = 0; j < 20; j++){
                jmp[i][j] = 0;
                mn[i][j] = 1e9;
            }

        }

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
                sz = 0;
                good[comp[i]] = !color(i, 1);
                flag |= (sz > 1) & (sz & 1);
            }
        }       

        for(int i = 1; i <= cnt; i++){
            for(int j = 0; j < MAXB; j++) mn[i][j] = 1e9;
        }  

        bfs();

        init(1);

        /*
                1               7
                |               |
                3               6
               / \             / \
              4   2           2  10
              |               |
              5               1

        */

        int q; cin >> q;

        long long ans = 0;

        while(q--){
            int x,y; cin >> x >> y;

            if(!flag) ans--;
            else ans += min({dp[comp[x]], dp[comp[y]], lca(comp[x],comp[y])});
        }       

        cout << "Case #" << _ << ": " << ans << "\n";
    }
}