#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        vector<int> a(n+1);
        vector<int> psa(n+1);

        map<int, vector<int>> mp;
        

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            psa[i] = (a[i] + psa[i-1]) % k;
            mp[psa[i]].push_back(i);
        }
       
        int ans = 0;
        for(int i = 1; i <= n; i++){
            //psa[r] - psa[l-1] + MOD= 0

            int lo = 0;
            if(!mp[psa[i-1]].size()) continue;
            int hi = mp[psa[i-1]].size()-1;

            int pos = hi+1;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(mp[psa[i-1]][mid] >= i + k){
                    pos = mid;
                    hi = mid-1;
                }
                else lo = mid+1;
            }

            //cout << i << " " << mp[psa[i-1]][pos] << "\n";

            ans += mp[psa[i-1]].size() - pos;

            
        }

        cout << ans << "\n";



    
    }
}