#include <bits/stdc++.h>
#include <iostream>


#define int long long

using namespace std;

const int MAXN = 2e5+5;


int n, a[MAXN],g[MAXN], q;



int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

int lcm(int a, int b){
    return a*b / gcd(a,b);
}

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    g[0] = 1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        if(g[i-1] > 1e9 || lcm(a[i], g[i-1]) > 1e9) g[i] = 1e9+1;
        else g[i] = lcm(a[i], g[i-1]);
        
    }

    while(q--){
        int x; cin >> x;

        if(x == 0){
            cout << "-1\n";
            continue;
        }

        int lo = 1;
        int hi = n;
        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            //cout << mid << " " << g[mid] << "\n";

            if(x % g[mid] != 0 || g[mid] > 1e9){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }

        cout << ans << "\n";
    }

}