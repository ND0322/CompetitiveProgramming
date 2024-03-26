#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 5e5+5;
const int MOD = 1e9+7;

int n, m, disc[MAXN], low[MAXN], cnt, t = 1, a[MAXN], sum[MAXN], comp[MAXN];

pair<int,int> dp[MAXN][2];

bool in[MAXN];

vector<int> adj[MAXN], adjSCC[MAXN];

stack<int> st;


void tarjans(int node){
    low[node] = disc[node] = t++;

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
        while(st.top() != node){
            in[st.top()] = 0;
            comp[st.top()] = cnt;
            sum[cnt] += a[st.top()];
            st.pop();
        }
        in[node] = 0;
        comp[node] = cnt;
        sum[cnt] += a[node];
        st.pop();
        cnt++;
    }    
}

pair<int,int> dfs(int node, bool take){
    if(node == comp[n]){
        if(take) return {0,1};
        else return {sum[node],1};
    }


    //cout << node << " " << take << "\n";
    if(dp[node][take].first == -1){
        pair<int,int> &ans = dp[node][take];
       

        ans = {0,0};
        for(int child : adjSCC[node]){

            pair<int,int> opt2 = dfs(child,0);
            pair<int,int> opt1 = dfs(child,1);
            if(!take){
                if(opt1.first + sum[node] > ans.first) ans = {opt1.first + sum[node],opt1.second};
                else if(opt1.first + sum[node] == ans.first) ans.second = (ans.second + opt1.second) % MOD;
            }
            
            if(opt2.first > ans.first) ans = {opt2.first,opt2.second};
            else if(opt2.first == ans.first) ans.second = (ans.second + opt2.second) % MOD;
        }
    }
    return dp[node][take];
    
}

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        if(x == y) continue;
        adj[x].push_back(y);
    }

    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end() );
        adj[i].erase(unique(adj[i].begin(), adj[i].end() ), adj[i].end());
    }

    for(int i = 1; i <= n; i++){
        if(!disc[i]) tarjans(i);
    }

    for(int i = 1; i <= n; i++){
        for(int j : adj[i]){
            if(comp[i] == comp[j]) continue;
            adjSCC[comp[i]].push_back(comp[j]);
        }
    }

    for(int i = 0; i < cnt; i++){
        sort(adjSCC[i].begin(), adjSCC[i].end() );
        adjSCC[i].erase(unique(adjSCC[i].begin(), adjSCC[i].end() ), adjSCC[i].end());
        dp[i][0].first = -1;
        dp[i][1].first = -1;
    }

    pair<int,int> ans = dfs(comp[1],0);

    cout << ans.first << " " << ans.second << "\n";


}