#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;


const int MAXN = 2e5+5;

int n, dp[MAXN], a[MAXN];

long long ans = 0;

vector<int> adj[MAXN];

void dfs(int node, int par){
    int tmp = dp[a[node]];
    ans += tmp;

    for(int child : adj[node]){
        if(child == par) continue;
        dp[a[node]] = 1;
        dfs(child, node);
    }

    dp[a[node]] = tmp+1;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i] = 0;
            adj[i].clear();
        }

        for(int i = 0; i < n-1; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        ans = 0;
        dfs(1,-1);

        cout << ans << "\n";
    }
}

/*
    1 - 2 - 3
    1   2   1
*/