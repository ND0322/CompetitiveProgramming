#include <bits/stdc++.h>
#include <iostream>

#define int long long

/*
for example y = 3

after removing all multiples of 3
keep track of length
build in reverse 
*/

using namespace std;

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        long long n, a, b; cin >> n >> a >> b;

        vector<long long> l(n+1);

        l[0] = 1e12+1;

        for(int i = 1; i <= n; i++) l[i] = l[i-1] - l[i-1]/a;

        if(l[n] < b){
            cout << "-1\n";
            continue;
        }

    

        for(int i = n; i >= 1; i--){
            long long hi = l[i];
            int lo = 1;

            int ans = -1;

            while(lo <= hi){
                long long mid = (lo+hi)>>1;

                if(mid - mid / a >= b){
                    hi = mid-1;
                    ans = mid;
                }
                else lo = mid+1;
            }

            b = ans;
            if(ans == -1) break;
        }

        cout << b << "\n";
    }
}