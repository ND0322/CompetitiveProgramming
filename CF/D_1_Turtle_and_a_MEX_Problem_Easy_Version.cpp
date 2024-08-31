#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

//more than 2e5 is just x
//bfs?

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;


        vector<int> l(n+1);
        vector<set<int>> a(n+1);

        for(int i = 1; i <= n; i++){
            cin >> l[i];

            for(int j = 1; j <= l[i]; j++){
                int x; cin >> x;
                a[i].insert(x);
            }
        }

        map<int,int> mp;

        //maps left to right range

        int extra = 0;

        for(int i = 1; i <= n; i++){
            bool flag = 0;
            bool flag2 = 0;
            int gap = 0;
            for(int j = 0; j <= l[i]+1; j++){
                if(a[i].find(j) == a[i].end()){
                    if(!flag){
                        gap = j;
                        flag = 1;
                        
                    }
                    else{
                        mp[gap] = max(mp[gap], j);
                        flag2 = 1;
                        break;
                    }
                }
            }

            extra = max(extra, gap);
            extra = max(extra, mp[gap]);
        }
        int ans = 0;

        for(int i = 0; i <= min(extra, m); i++) ans += extra;

        if(m > extra) ans += ((m - (extra+1) + 1) * (m + extra+1)) / 2.0;

        cout << ans << "\n";



    }
}