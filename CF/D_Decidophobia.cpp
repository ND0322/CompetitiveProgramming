#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 6e5+5;

int a[MAXN], psa[MAXN];



/*
n * a[i] - sm 

2n * a[i] - sm
*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, d; cin >> n >> d;



        for(int i = 1; i <= n; i++){
            cin >> a[i];

            a[i+n] = a[i];
            a[i+2*n] = a[i];
        }

        for(int i = 1; i <= 3 * n; i++) psa[i] = psa[i-1] + a[i];


        int ans = 0;
        for(int i = 1; i <= n; i++) ans += max(0LL, 2*d*a[i] - (psa[i+n+d] - psa[i+n-d-1] - a[i]));
        

        cout << ans << "\n";

    }
}