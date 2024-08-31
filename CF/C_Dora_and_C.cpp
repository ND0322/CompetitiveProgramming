#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

//basically the observation is because we took mod of the gcd, all numbers to the right will be within the rnag

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);    
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,x,y; cin >>n >> x >> y;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i] %= gcd(x,y);
        }

        sort(a.begin(), a.end());

        int ans = a[n] - a[1];

        for(int i = 1; i < n; i++) ans = min(ans, gcd(x,y) + a[i] - a[i+1]);

        cout << ans << "\n";

       

        
    }
}