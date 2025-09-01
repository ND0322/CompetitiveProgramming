#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, dp[MAXN][2], a[MAXN], c[MAXN], low[MAXN], disc[MAXN], comp[MAXN], sz[MAXN], cnt, t;

bool vis[MAXN], in[MAXN];

vector<int> adj[MAXN], rts;

stack<int> st;

void tarjans(int node){
    low[node] = disc[node] = ++t;

    in[node] = 1;
    st.push(node);

    for(int child : adj[node]){
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
            sz[cnt]++;
            in[st.top()] = 0;
            st.pop();
        }

        comp[node] = cnt;
        sz[cnt]++;
        in[node] = 0;
        st.pop();
        
    }
}

void dfs(int node, int par, int rt){
    
    //buy this node?
    dp[node][0] = c[node] * (a[node] != node);

    int opt0 = 0;
    int opt1 = 0;

    

    for(int child : adj[node]){
        if(child == par || child == rt) continue;
        dfs(child, node, rt);

        opt0 += dp[child][0];
        opt1 += dp[child][1];
    }

 
    dp[node][0] += opt1;
    dp[node][1] = min(c[node] * (a[node] != node) + opt1, opt0);
}

int sub2(int node){
    dfs(node, -1, node);

    int ans = dp[node][0];


    dfs(a[node], -1, a[node]);


    return min(ans, dp[a[node]][0]);
}

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i == a[i]) continue;

        adj[a[i]].push_back(i);
    }


    for(int i = 1; i <= n; i++) cin >> c[i];

    for(int i = 1; i <= n; i++){
        if(!disc[i]) tarjans(i);
    }


    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(vis[comp[i]]) continue;
        if(sz[comp[i]] == 1 && a[i] != i) continue;

        ans += sub2(i);

        vis[comp[i]] = 1;
    }

    cout << ans << "\n";
}