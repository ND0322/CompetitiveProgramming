#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,f; cin >> n >> f;

        set<int> sect;

        int a,b,c,d; cin >> a >> b >> c >> d;

        vector<vector<pair<int,int>>> rocks(n+1);
        for(int i = 1; i <= n; i++){
            int x,y; cin >> x >> y;

            rocks[i].push_back({x,y});
            cin >> x >> y;

            rocks[i].push_back({x,y});
            cin >> x >> y;

            rocks[i].push_back({x,y});
        }

        for(int i = 0; i <= f; i++){
            

            for(int j = 1; j <= n; j++){
                int cross1 = (rocks[j][1].first - rocks[j][0].first) * (b - rocks[j][0].second) - (rocks[j][1].second - rocks[j][0].second) * (a - rocks[j][0].first);
                int cross2 = (rocks[j][2].first - rocks[j][1].first) * (b - rocks[j][1].second) - (rocks[j][2].second - rocks[j][1].second) * (a - rocks[j][1].first);
                int cross3 = (rocks[j][0].first - rocks[j][2].first) * (b - rocks[j][2].second) - (rocks[j][0].second - rocks[j][2].second) * (a - rocks[j][2].first);

                //cout << a << " " << b << " " << j << " " << cross1 << " " << cross2 << " " << cross3 << "\n"; 
                if((cross1 <= 0) == (cross2 <= 0) && (cross1 <= 0) == (cross3 <= 0)) sect.insert(j);
                if((cross1 >= 0) == (cross2 >= 0) && (cross1 >= 0) == (cross3 >= 0)) sect.insert(j);
            }

            a += c;
            b += d;
        }

        cout << sect.size() << "\n";
        
    }
}