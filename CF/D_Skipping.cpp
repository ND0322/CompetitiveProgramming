#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long

//prefix is always possible

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        vector<int> dist(n+1, 1e18);

        dist[1] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, 1});

        while(pq.size()){
            auto [d, node] = pq.top();

            pq.pop();

            if(node != 1 && dist[node-1] > d){
                dist[node-1] = d;
                pq.push({d, node-1});
            }

            if(dist[b[node]] > d + a[node]){
                dist[b[node]] = d + a[node];

                pq.push({d + a[node], b[node]});
            }
        } 

        int ans = 0;

        int sm = 0;
        for(int i = 1; i <= n; i++){
            sm += a[i];

            ans = max(ans, sm - dist[i]);
        }

        cout << ans << "\n";
        
    }
}