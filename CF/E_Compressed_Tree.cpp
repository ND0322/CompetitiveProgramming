#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 5e5+5;

int n;


long long dp[MAXN][4], a[MAXN];;

//0 to 2 cut that many edges
//3 cut 3 or more edges


vector<int> adj[MAXN];

void dfs(int node, int par){
    dp[node][0] = a[node];

    vector<long long> tmp;

    for(int child:adj[node]){
        if(child == par) continue;

        dfs(child,node);

        tmp.push_back(max({dp[child][0], dp[child][1] - a[child], dp[child][2] + a[child], dp[child][3]}));

    }


    sort(tmp.begin(), tmp.end());
    if(tmp.size() >= 1) dp[node][1]  = tmp[0] + a[node];
    if(tmp.size() >= 2) dp[node][2] = tmp[0] + tmp[1];
    if(tmp.size() >= 3){
        dp[node][3] = a[node];
        for(int i = 0; i < tmp.size(); i++){
            if(tmp[i] > 0) dp[node][3] += tmp[i];
        }
    }
    
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = -1e18;
            adj[i].clear();

        }


        for(int i = 0; i < n-1; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1,0);

        long long ans = 0;

        for(int i = 1; i <= n; i++) ans = max({ans, dp[i][0], dp[i][1], dp[i][2], dp[i][3]});

        cout << ans << "\n";
        

    }
}

