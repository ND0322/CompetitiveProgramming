#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long



int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);
        vector<int> cnt(n+1);

        

        for(int i = 0; i < n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
       
        
        long long pref = 0;
        long long ans = 0;
        for(int i = 0; i <= n; i++){
            if(cnt[i] >= 2) ans += ((cnt[i] * (cnt[i]-1))/2) * (pref);
            if(cnt[i] >= 3) ans += (cnt[i] * (cnt[i]-1) * (cnt[i]-2))/6;
            pref += cnt[i];
            //cout << i << " " << suf[i] << " " << (suf[i]-1) << " " << (suf[i]-2) << "\n";
        }

        cout << ans << "\n";
        






    }


}


/*
try to solve a quickly
b go with your instinct instead of just sitting there
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/