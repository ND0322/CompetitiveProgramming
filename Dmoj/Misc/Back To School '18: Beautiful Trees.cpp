#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e5+5;

int n, dp[MAXN], ans;

bool good[MAXN], vis[MAXN];

vector<int> adj[MAXN];

void dfs(int node, int par){

    vis[node] = 1;

    pair<int,int> best = {0, -1};
    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node);
        best = max(best, {dp[child]+1, child});
    }

    dp[node] = best.first;

    int sec = 0;

    for(int child : adj[node]){
        if(child == par || child == best.second) continue;
        sec = max(sec, dp[child]+1);
    }

    ans = max(ans, best.first + sec);
}


int main(){
    cin >> n;

    memset(good, 1, sizeof(good));

    for(int i = 1; i <= n; i++){
        long long x; cin >> x;

        if(((long long)sqrt(x)) * ((long long)sqrt(x)+1) != x) good[i] = 0; 
    }

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        if(!good[x]||!good[y]) continue;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        dfs(i, -1);
    }

    bool flag = 1;

    for(int i = 1; i <= n; i++){
        if(good[i]) flag = 0;
    }

    if(flag){
        cout << "0\n";
        return 0;
    }
    cout << ans+1 << "\n";




}