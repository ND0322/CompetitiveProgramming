#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

#define int long long

int a[MAXN];

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, x; cin >> n >> x;

        for(int i = 1; i <= n; i++) cin >> a[i];

        int mx = 0;
        int sm = 0;

        for(int i = 1; i <= n; i++){
            mx = max(mx, a[i]);
            sm += a[i];
        }


        
        cout << max(mx, (int)ceil(sm /(double)x)) << "\n";

        
    }
}