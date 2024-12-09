#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m, l; cin >> n >> m >> l;
    
        vector<pair<int,int>> a;

        for(int i = 0; i < n; i++){
            int l,r; cin >> l >> r;

            a.push_back({l,r});
        }

        vector<pair<int,int>> b;

        for(int i = 0; i < m; i++){
            int x,y; cin >> x >> y;

            b.push_back({x,y});
        }

        priority_queue<int> pq;

        int i = 0;
        int cur = 1;
        int ans = 0;
        bool flag = 1;
        for(auto [l,r] : a){
            while(i < b.size() && b[i].first < l){
                pq.push(b[i].second);
                i++;
            }

            while(cur <= r-l+1){
                if(pq.empty()){
                    flag = 0;
                    break;
                }
                cur += pq.top();
                pq.pop();
                ans++;
            }
        }

        cout << (!flag ? -1 : ans) << "\n";

        
    }
}