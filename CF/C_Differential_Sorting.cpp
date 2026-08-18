#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        if(a[n] < a[n-1]){
            cout << "-1\n";
            continue;
        }

        int pos = 0;

        int last = a[n-1];

        if(a[n-1] >= 0) pos = n-1;
        if(a[n] >= 0) pos = n;
        
        bool flag = 0;

        vector<pair<int,pair<int,int>>> ans;

        for(int i = n-2; i >= 1; i--){
            if(a[i] <= last){
                last = a[i];
                if(a[i] >= 0 && !pos) pos = i;
                continue;
            }

            if(!pos){
                flag = 1;
                break;
            }

            ans.push_back({i, {i+1, pos}});
            a[i] = last - a[pos];
            last = a[i];
        }

        if(flag){
            cout << "-1\n";
            continue;
        }

        cout << ans.size() << "\n";

        for(auto i : ans) cout << i.first << " " << i.second.first << " " << i.second.second << "\n";

        
    }



}