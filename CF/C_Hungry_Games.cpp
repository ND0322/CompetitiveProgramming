#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, x;

long long a[MAXN], psa[MAXN], dp[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> x;

        for(int i =1 ; i <= n; i++){
            cin >> a[i];
            psa[i] = psa[i-1] + a[i];
        }
        fill(dp, dp+n+5, 0);
        psa[n+1] = 0;

        for(int i = n; i >= 1; i--){
            int lo = i;
            int hi = n+1; 

            int nxt = n+1;


            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(psa[mid] - psa[i-1] > x){
                    hi = mid-1;
                    nxt = mid;
                }
                else lo = mid+1;
            }
            dp[i] = dp[nxt+1] + nxt - i;
            
        }

        long long ans = 0;

        for(int i = 1; i <= n; i++) ans += dp[i];
        cout << ans << "\n";
    }
}