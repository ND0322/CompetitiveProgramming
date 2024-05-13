#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, a[MAXN];

long long k, psa[MAXN];

bool can(int x){
    for(int i = 1; i <= n; i++){
        if(x - i + 1 >= 0 && psa[n-i] - a[1] + (a[1] - x + i - 1)*i <= k) return 1;
    }
    return 0;
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;


        long long sm = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sm += a[i];
        }

        sort(a+1,a+n+1);

        for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + a[i];

        //bsearch number dec
        int lo = 0;
        int hi = sm;
        int ans = 0;



        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(can(mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        cout << ans << "\n";
    }
}