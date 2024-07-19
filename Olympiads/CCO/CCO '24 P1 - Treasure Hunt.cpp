#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1e6+5;

int n, m, a[MAXN], dp[MAXN];

vector<pair<int,int>> adj[MAXN];



int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = a[i];
    }
    for(int i = 1; i <= m; i++){
        int x,y,c; cin >> x >> y >> c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    priority_queue<pair<int,int>> pq;

    for(int i = 1; i <= n; i++) pq.push({dp[i], i});

    while(pq.size()){
        auto [d,node] = pq.top();

        pq.pop();

        if(d != dp[node]) continue;

        for(auto [child, weight] : adj[node]){

            if(dp[child] < dp[node] - weight){
                dp[child] = dp[node] - weight;
                pq.push({dp[child], child});
            }
        }

    }

    for(int i = 1; i <= n; i++) cout << dp[i] << "\n";


    

   
}