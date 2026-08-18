#include <bits/stdc++.h>
#include <iostream>


using namespace std;

#define int long long


int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<pair<int,int>> a(n+1);
        vector<int> psa(n+1);
        vector<pair<int,int>> bounds(n+2, {1e9, 0});

        vector<vector<int>> p(n+2);
        
        for(int i = 1; i <= n; i ++){
            cin >> a[i].first >> a[i].second;
            p[a[i].first].push_back(a[i].second);
    
            

            psa[a[i].second] = 1;
        }
    
        for(int i = 1; i <= n; i++) psa[i] += psa[i-1];
        
        
        int mn = 1e9;
        int mx = 0;

        for(int i = n; i >= 1; i--){
            int lo = 1e9;
            int hi = 0;

            for(int j : p[i+1]){
                lo = min(lo, j);
                hi = max(hi, j);
            }
            bounds[i].first = min(bounds[i+1].first, lo);
            bounds[i].second = max(bounds[i+1].second, hi);
        }



        int ans = 0;
        for(int x = 1; x <= n; x++){
            vector<int> v = p[x];
            if(v.empty()) continue;

            for(int i : v){
                mn = min(mn, i);
                mx = max(mx, i);
            }

            int lo = max(mn, bounds[x].first);
            int hi = min(mx, bounds[x].second); 
            


            if(hi < lo) continue;
            ans += psa[hi] - psa[lo];
        }

        cout << ans << "\n";

        

       

    }
}