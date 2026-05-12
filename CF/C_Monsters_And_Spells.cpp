#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


/*
when is it worth resetting 
for each element we know the latest it can start
*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<pair<int,int>> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i].first;
        
        map<int,vector<bool>> events;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            a[i].second = a[i].first - x+1;
            events[a[i].second].push_back(1);
            events[a[i].first+1].push_back(0);
        }


        int actv = 0;
        int l = 0;
        int ans = 0;

        for(auto [x,v] : events){
            int tmp = actv;
            sort(v.begin(), v.end());

            for(bool i : v){
                if(i) break;
                actv--;
            }

            if(tmp && !actv) ans += (x-l) * (x-l+1)/2;   
            tmp = actv;

            for(bool i : v){
                if(!i) continue;
                actv++;
            }

            if(!tmp && actv) l = x;
           
            
            
    
            
            
        }

        cout << ans << "\n";

        
    }
}