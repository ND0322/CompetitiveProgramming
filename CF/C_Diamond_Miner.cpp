#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> vert;
        vector<int> horz;

        for(int i = 0; i < 2*n; i++){
            int x,y; cin >> x >> y;

            if(x == 0) vert.push_back(abs(y));
            else horz.push_back(abs(x));
        }

        sort(vert.begin(), vert.end());
        sort(horz.begin(), horz.end());

        long double ans = 0;

        for(int i = 0; i < n; i++) ans += sqrt(vert[i] * vert[i] + horz[i] * horz[i]);

        cout << setprecision(9) << fixed << ans << "\n";

    }
}