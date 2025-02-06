#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2005;

int n,m, low[MAXN], disc[MAXN], t, cnt, comp[MAXN], deg[MAXN], dp[MAXN]; 

vector<pair<int,bool>> adj[MAXN];

vector<int> adjSCC[MAXN];

stack<int> st;

bool in[MAXN], vis[MAXN];

void tarjans(int node){
    low[node] = disc[node] = ++t;

    st.push(node);

    in[node] = 1;

    for(auto [child, t] : adj[node]){
        if(!disc[child]){
            tarjans(child);
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

void dfs(int node){

    if(vis[node]) return;
    vis[node] = 1;
    
    for(int child : adjSCC[node]){
        dfs(child);
        dp[node] = max(dp[node], dp[child]);
    }

    dp[node]++;
}



int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;

            if(c == '>') adj[i].push_back({n+j,0});
            if(c == '<') adj[n+j].push_back({i,0});

            if(c == '='){
                adj[i].push_back({n+j,1});
                adj[n+j].push_back({i,1});
            }
        }
    }

    for(int i = 1; i <= n+m; i++){
        if(!disc[i]) tarjans(i);
    }

    bool flag = 1;

    for(int i = 1; i <= n+m; i++){
        for(auto [child, t] : adj[i]){
            if(comp[i] == comp[child] && !t) flag = 0;
            if(comp[i] != comp[child]){
                adjSCC[comp[i]].push_back(comp[child]);
                deg[comp[child]]++;
            }
        }
    }

    if(!flag){
        cout << "No";
        return 0;
    }


    for(int i = 1; i <= cnt; i++){
        if(!deg[i]) dfs(i);
    }

    cout << "Yes\n";
    for(int i = 1; i <= n; i++) cout << dp[comp[i]] << " ";
    cout << "\n";
    for(int i = n+1; i <= n+m; i++) cout << dp[comp[i]] << " ";
    cout << "\n";



}