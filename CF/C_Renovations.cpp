#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

#define int long long

const int MAXN = 2e5+5;
const int MAXD = 19;

int n,m, k, disc[MAXN],low[MAXN],cnt,t, comp[MAXN], sz[MAXN], par[MAXN], jmp[MAXN][MAXD], dist[MAXN][MAXD], cntt[MAXN][MAXD], depth[MAXN];

bool in[MAXN];

stack<int> st;

vector<pair<int,int>> adj[MAXN], adj2CC[MAXN];

//solving
//https://judge.yosupo.jp/problem/two_edge_connected_components

void tarjans(int node,int par){
    disc[node] = low[node] = ++t;
    

    in[node] = 1;
  
    st.push(node);

    for(auto [child, weight] : adj[node]){

        
        if(child == par){
            par = -1;
            continue;
        }

        if(!disc[child]){
            tarjans(child,node);
            low[node] = min(low[node],low[child]);
        }
        else if(in[child]) low[node] = min(low[node],disc[child]);
        
    }

    if(low[node] == disc[node]){
        while(st.top() != node){
            
            comp[st.top()] = cnt;
            sz[cnt]++;
            in[st.top()] = 0;
            st.pop();
        }

        
        comp[node] = cnt;
        sz[cnt]++;
        in[node] = 0;
        st.pop();

        cnt++;
    }
}

void dfs(int node){
    for(int i = 1; i < MAXD; i++){
        jmp[node][i] = jmp[jmp[node][i-1]][i-1];
        dist[node][i] = dist[node][i-1] + dist[jmp[node][i-1]][i-1];
        cntt[node][i] = cntt[node][i-1] + cntt[jmp[node][i-1]][i-1];
    }

    for(auto [child, weight] : adj2CC[node]){
        if(jmp[node][0] == child) continue;
        depth[child] = depth[jmp[child][0] = node]+1;
        dist[child][0] = weight;
        cntt[child][0] = sz[node];
        dfs(child);
    }
}

pair<int,int> lift(int node, int d){
    pair<int,int> ans = {0,0};
    for(int i = 0; i < MAXD; i++){
        if(d&(1<<i)){
            ans.first += dist[node][i];
            ans.second += cntt[node][i];
            node = jmp[node][i]; 
        }

    }
    return ans;
}

int32_t main(){
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    for(int i = 0; i < n; i++){
        if(!disc[i]) tarjans(i,-1);
    }

    for(int i = 0; i < n; i++){
        for(auto [child, weight] : adj[i]){
            if(comp[i] == comp[child]) continue;
            adj2CC[comp[i]].push_back({comp[child], weight});
            adj2CC[comp[child]].push_back({comp[i],weight});
        }
    }

    for(int i = 0; i < cnt; i++){
        sort(adj2CC[i].begin(), adj2CC[i].end() );
        adj2CC[i].erase(unique(adj2CC[i].begin(), adj2CC[i].end()), adj2CC[i].end());
    }

   
    dfs(0);

    long long tot = 0;

    for(int i = 0; i < cnt; i++){
        int lo = 0;
        int hi = depth[i]-1;

        int ans = 0;

        tot += (sz[i] * (sz[i]-1)) / 2;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(lift(i, mid).first <= k){
                lo = mid+1;
                ans = lift(i,mid).second;
            }
            else hi = mid-1;
        }

        tot += sz[i] * ans;
    }

    cout << tot << "\n";
    
}



