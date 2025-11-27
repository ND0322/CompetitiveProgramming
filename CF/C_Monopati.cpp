#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

/*

connected prefix of ones in first and suffix in second 
for each i we will have a minimum and maximum 
*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+5);
        vector<int> b(n+5);

        vector<int> pmx(n+5);
        vector<int> pmn(n+5, 1e9);

        vector<int> smx(n+5);
        vector<int> smn(n+5, 1e9);
        for(int i = 1; i <= n; i++){
            cin >> a[i];

            pmx[i] = max(pmx[i-1], a[i]);
            pmn[i] = min(pmn[i-1], a[i]);
        }

        for(int i = 1; i <= n; i++) cin >> b[i];

        for(int i = n; i >= 1; i--){
            smx[i] = max(smx[i+1], b[i]);
            smn[i] = min(smn[i+1], b[i]);
        }




        vector<pair<int,int>> ranges;

        for(int i = 1; i <= n; i++) ranges.push_back({min(pmn[i], smn[i]), max(pmx[i], smx[i])});

        map<int,int> mp;
        for(auto [l,r] : ranges){


            if(mp.find(l) == mp.end()) mp[l] =r;
            else mp[l] = min(mp[l], r);
        }

        set<pair<int,int>> s;

        for(auto [l,r] : mp) s.insert({r, l});

        int ans = 0;
        for(int i = 1; i <= 2 * n; i++){
            if(s.empty()) break;
            ans += 2 * n - (*s.begin()).first + 1;
            
            if(s.find({mp[i], i}) != s.end()) s.erase({mp[i], i});
        }

        cout << ans << "\n";
        
        


    }
}