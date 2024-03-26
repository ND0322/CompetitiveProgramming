#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        long long sum = 0;
        long long mx = 0;
        long long mn = 1e9;

        for(int i = 0; i < n; i++){
            long long x; cin >> x;

            sum += x;
            mx = max(mx,x);
            mn = min(mn, x);
        }

        cout << (n+sum - mn + mx <= m ? "YES\n" : "NO\n");
    }
}