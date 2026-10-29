#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
upper bound we can always just add one extra per disconnected point 
this can only be improved if we can place one middle point that helps two people 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin(), a.end());


        int lo = 1;
        int hi = 1e9;

        int ans = 1e9;


        while(lo <= hi){
            int mid = (lo + hi) >> 1;


            vector<int> dp(n+2);             
            
            for(int i = n; i >= 1; i--){
                dp[i] = dp[i+1] + 1;

                //if me and next 
                if(i < n){
                    dp[i] = min(dp[i], dp[i+2] + (a[i+1] - a[i] - 1) / mid );
                    dp[i] = min(dp[i], dp[i+1] + (a[i+1] - a[i] - 1) / mid );
                }
            }



            if(dp[1] <= k){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }

        cout << ans << "\n";
    }
}