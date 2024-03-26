#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, b,x, a[MAXN];


//ternary search + math ig

int f(int k){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int cnt = a[i]/k;



        ans += ((a[i] - cnt - 1) * (cnt+1) * (a[i] - cnt * (k - a[i] + cnt * k))/(cnt+1) + (a[i] - cnt) * cnt * (k - a[i] + cnt * k) + 1)/2 * b;
    }

    return ans - (k-1) * x;
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> b >> x;

        int lo = 1;
        int hi = 0;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            hi += a[i];
        }

        int ans = 0;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            ans = max(ans, f(mid));
            ans = max(ans, f(mid+1));

            if(f(mid) < f(mid+1)) lo = mid+1;
            else hi = mid-1;
        }

        cout << ans << "\n";


        
       
    }
}
