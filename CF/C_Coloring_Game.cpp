#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

/*
casework

b will either choose max of array or - 2 * max(red) 


let the triple be (a,b,c) where a < b < c

number of a + b > max(2 * c, mx - c)
*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        long long ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                //first thing that meets mx - condition

                int lo = j+1;
                int hi = n;

                int l = n+1;
                while(lo <= hi){
                    int mid = (lo+hi)>>1;

                    if(a[i] + a[j] > a[n] - a[mid]){
                        hi = mid-1;
                        l = mid;
                    }
                    else lo = mid+1;
                }

                lo = j+1;
                hi = n;

                int r = -1;

                while(lo <= hi){
                    int mid = (lo+hi)>>1;

                    if(a[i] + a[j] > a[mid]){
                        lo = mid+1;
                        r = mid;
                    }
                    else hi = mid-1;
                }
                ans += max(r - l + 1, 0LL);
            }

        }

        cout << ans << "\n";
    }
}