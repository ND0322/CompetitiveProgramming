#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
each thing must attack at least once -> either 1 or 2 things die per turn
small ai can attack a big ai to save turns 
*/

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<pair<int,int>> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());

        if(m){
            //pair each of the m keeps with one kill
            //everything else needs to be gone

            if(n - 2*m < 0){
                cout << "-1\n";
                continue;
            }

            vector<pair<int,int>> ans;

            for(int i = 1; i <= n-2*m; i++) ans.push_back({a[i].second, a[i+1].second});
            for(int i = n-2*m + 1; i <= n-m; i++) ans.push_back({a[i+m].second, a[i].second});
            cout << ans.size() << "\n";
            for(auto i : ans) cout << i.first << " " << i.second << "\n";
        }
        else{

            vector<pair<int,int>> ans, tmp;
            int sm = 0;
            for(int i = 1; i <= n-1; i++) sm += a[i].first;
            if(sm < a[n].first){
                cout << "-1\n";
                continue;
            }


            sm = 0;
            int k = -1;

            for(int i = n-1; i >= 1; i--){
                sm += a[i].first;
                tmp.push_back({a[i].second, a[n].second});
                if(sm > a[n].first){
                    k = i-1;
                    break;
                }
            }


            for(int i = 1; i <= k; i++) ans.push_back({a[i].second, a[i+1].second});
            for(auto i : tmp) ans.push_back(i);
            cout << ans.size() << "\n";
            for(auto i : ans) cout << i.first << " " << i.second << "\n";
        }
    }

    
}