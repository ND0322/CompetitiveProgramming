#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

#define int long long

int n, a[MAXN], psa[MAXN], dp[MAXN], l, r;

//dp + bsearch for the transitions
int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> l >> r;

        for(int i = 1; i <= n; i++)cin >> a[i];

        for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + a[i];

        dp[n+1] = 0; 
        for(int i = n; i >= 1; i--){
            dp[i] = dp[i+1];

            int nxt = -1;
            int lo = i;
            int hi = n;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(psa[mid] - psa[i-1] >= l){
                    hi = mid-1;
                    nxt = mid;
                }
                else lo = mid+1;
            }

            if(psa[nxt] - psa[i-1] > r || nxt == -1) continue;
            dp[i] = max(dp[i], dp[nxt+1] + 1);
        }

        cout << dp[1] << "\n";


    }
}