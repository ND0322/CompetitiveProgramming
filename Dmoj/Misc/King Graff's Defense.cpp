#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

#define int long long

const int MAXN = 1e6+5;

int n, m, low[MAXN], disc[MAXN], t, sz[MAXN], cnt;

bool in[MAXN];

stack<int> st;
vector<int> adj[MAXN];

void tarjan(int node, int par){
    disc[node] = low[node] = ++t;
    in[node] = 1;
    st.push(node);

    for(int child : adj[node]){
        if(child == par) continue;
        

        if(!disc[child]){
            tarjan(child, node);
            low[node] = min(low[node], low[child]);
        }
        else if(in[child]) low[node] = min(low[node], disc[child]);
    }

    if(low[node] == disc[node]){
        cnt++;
        while(st.top() != node){
            sz[cnt]++;
            in[st.top()] = 0;
            st.pop();
        }

        sz[cnt]++;
        in[node] = 0;
        st.pop();
    }    
}

int32_t main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(!disc[i]) tarjan(i,-1);
    }

    long long ans = 0;
    for(int i = 1; i <= cnt; i++) ans += (sz[i] * (sz[i]-1))/2;

    cout << setprecision(5) << fixed << 1 - ans/(double)(n*(n-1)/2) << "\n";

    
}