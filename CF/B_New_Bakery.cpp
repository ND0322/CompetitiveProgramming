#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, a, b; cin >> n >> a >> b;

        if(a > b){
            cout << n*a << "\n";
            continue;
        }

        int k = min(b-a, n);

        
        cout << b * k - (k * (k+1)) / 2 + k + (n-k) * a << "\n";
        
        
    }
    


}