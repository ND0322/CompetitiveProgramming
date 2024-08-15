#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long



int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        long long k; cin >> k;

        long long ans = 0;

        vector<pair<int,int>> a(n+2);

        for(int i = 1; i <= n; i++) cin >> a[i].first;
        for(int i = 1; i <= n; i++) cin >> a[i].second;

        sort(a.begin()+1, a.end()-1);

        for(int i = 1; i <= n; i++){
            int m = k;

            int cnt1 = min(m/a[i].first,a[i].second);

            m -= cnt1 * a[i].first;

            int cnt2 = 0;

            if(i < n && a[i+1].first - a[i].first <= 1){
                cnt2 = min(m/a[i+1].first,a[i+1].second);
                m -= cnt2 * a[i+1].first;
            }

           

            int conv =max(0LL, min({cnt1, a[i+1].second - cnt2, m}));

            if(a[i+1].first != a[i].first+1) conv = 0;

            //cout << i << " " << cnt1 << " " << cnt2 << " " << m << " " << conv << "\n";

            ans = max(ans ,(cnt1 - conv) * a[i].first + (cnt2 + conv) * (a[i+1].first));

            
            
        }



        cout << ans << "\n";
    }
}