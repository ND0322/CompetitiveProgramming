#include <bits/stdc++.h>
#include <iostream>
#include <stack>


using namespace std;

const int MAXN = 1e4+5;
const int MOD = 1e9;

int n, m, low[MAXN], disc[MAXN], t, comp[MAXN], cmp;

long long dp[MAXN];

//W cycle detection algorithm 🐒

vector<int> adj[MAXN], aa[MAXN][2];

bool vis[MAXN], in[MAXN], flag, good[MAXN];

stack<int> st;

void mark(int node, bool s){
    vis[node] = 1;

    for(int child : aa[node][s]){
        if(!vis[child]) mark(child, s);
    }
}

void tarjans(int node){
    disc[node] = low[node] = ++t;
 
    in[node] = 1;
    st.push(node);
 
    for(int child:adj[node]){
        if(!disc[child]){
            tarjans(child);
 
            low[node] = min(low[node], low[child]);
        }
        else if(in[child]){
            low[node] = min(low[node], disc[child]);
        }
    }
 
    if(low[node] == disc[node]){
        int cnt = 0;
        cmp++;

        while(st.top() != node){
            cnt++;
            in[st.top()] = 0;
            comp[st.top()] = cmp;
            st.pop();
            
        }

        in[node] = 0;
        comp[node] = cmp;
        st.pop();
        cnt++;
        

        flag |= (cnt >= 2);        
    }

}

void dfs(int node){

    vis[node] = 1;
    if(node == 2){
        dp[node] = 1;
        return;
    }

    for(int child : adj[node]){
        if(!vis[child]) dfs(child);

        dp[node] += dp[child];
    }


}

int main(){
    int n,m; cin >> n >> m;

    vector<pair<int,int>> edges;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        edges.push_back({x,y});

        aa[x][0].push_back(y);
        aa[y][1].push_back(x);
    }
    
    mark(1, 0);

    for(int i = 1; i <= n; i++) good[i] = vis[i];

    memset(vis,0,sizeof(vis));

    mark(2,1);

    for(int i = 1; i <= n; i++) good[i] &= vis[i];


    for(auto [x,y] : edges){
        if(!good[x] || !good[y]) continue;
        adj[x].push_back(y);
    }



    for(int i = 1; i <= n; i++){
        if(good[i] && !disc[i]) tarjans(i);
        

        if(flag){
            cout << "inf\n";
            return 0;
        }
    }

    memset(vis, 0, sizeof(vis));
    dfs(1);

    if(ceil(log10(dp[1]) <= 9)) cout << dp[1] << "\n";
    else{
        dp[1] %= MOD;
        for(int i = 0; i < 9 - ceil(log10(dp[1])); i++) cout << "0";
        cout << dp[1] << "\n";
    }

    

   

   
}

