#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        map<int,int> mp;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            mp[x]++;
        }

        int mx = 0;

        vector<int> ans;

        for(auto i : mp){
            if(i.second >= 2) mx = max(mx, i.first);

            
        }

        mp[mx] -= 2;

        
        for(auto i : mp){
            for(int j = 0; j < i.second; j++) ans.push_back(i.first);
        }

        if(ans.size() < 2 || !mx){
            cout << "-1\n";
            continue;
        }

        pair<int,int> mn = {1e9, 1e9};
        
        
        for(int i = 0; i < ans.size()-1; i++){
            mn = min(mn, {ans[i+1] - ans[i], i});
        }



        if(2*mx <= mn.first) cout << "-1\n";
        else cout << mx << " " << mx << " " << ans[mn.second] << " " << ans[mn.second+1] << "\n";



    
    }
}