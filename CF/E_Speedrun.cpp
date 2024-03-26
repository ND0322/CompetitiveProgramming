#include <bits/stdc++.h>
#include <iostream>
#include <set>


using namespace std;

const int MAXN = 2e5+5;

int n,m,k;

long long dp[MAXN], a[MAXN];

vector<int> adj[MAXN];

bool start[MAXN], visited[MAXN];

vector<pair<long long, long long>> res;

multiset<long long> s;

void dfs(int node){
    visited[node] = 1;

    dp[node] = a[node];

    for(int child:adj[node]){
        if(!visited[child]) dfs(child);
        dp[node] = max(dp[node], dp[child] + (a[node]%k <= a[child]%k ? 0 : k));
    }
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m >> k;

        for(int i = 1; i <= n; i++){
            dp[i] = 0;
            start[i] = 1;
            visited[i] = 0;
            adj[i].clear();
            cin >> a[i];
        }

        res.clear();
        s.clear();

        for(int i = 0; i < m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            start[y] = 0;
        }

        for(int i = 1; i <= n; i++){
            if(start[i]){
                dfs(i);
                res.push_back({a[i], dp[i]});
                s.insert(dp[i]);
            }
        }

        sort(res.begin(), res.end());

        long long ans = 1e18;
        for(int i = 0; i < res.size(); i++){
            ans = min(ans, *s.rbegin() - res[i].first);
            s.erase(s.find(res[i].second));
            s.insert(res[i].second + k);
        }

        cout << ans << "\n";
    }
}