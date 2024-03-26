#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<long long> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int i = 0;
        int j = n-1;
        int ans = 0;
        long long cnt = 0;


        while(i < j){

            int x = min(a[i], a[j]-cnt);

            a[i] -= x;
            ans += x;
            cnt += x;

            if(a[j] == cnt){
                cnt = 0;
                ans++;
                j--;
            }

            i += !(a[i]);

        }

        if(i == j){
            if(a[i] == 1) ans += 1;
            else ans += (a[i] - cnt + 1) / 2 + 1;
        }

        cout << ans << "\n";

       

    }
}