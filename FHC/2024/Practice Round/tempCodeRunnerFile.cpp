#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n;
        double k; 
        cin >> n >> k;
        //might need quick pow

        

        long long lo = 0;
        long long hi = 1e8 * (100 - k);

        k /= 100;

        

        double ans = -1;
        while(lo <= hi){
            long long mid = (lo+hi)>>1;

            if(pow(k, n-1) <= pow(k+mid / 1e8, n)){
                hi = mid-1;
                ans = mid/1e6;
            }
            else lo = mid+1;
        }

        cout << setprecision(6) << fixed << "Case #" << _ << ": " << ans << "\n";
    }
}