#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 805;

int n,m, a[MAXN][MAXN], psa[MAXN][MAXN];





int32_t main(){
    cin >> n >> m;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) psa[i][j] = psa[i][j-1] + a[i][j];
    }

    int ans = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            if(i - j+1 < 1 || i+j > m) continue;

            map<int,set<int>> mp;
            mp[0].insert(0);
            int pref = 0;
            for(int k = 1; k <= n; k++){
                pref += psa[k][i] - psa[k][i-j];
                pref -= psa[k][i+j] - psa[k][i];

                mp[pref].insert(k);
            }
            for(auto [x,y] : mp) ans = max(ans, (*y.rbegin() - *y.begin()) * 2 * j);
            
            
        }
    }

    cout << ans << "\n";




}