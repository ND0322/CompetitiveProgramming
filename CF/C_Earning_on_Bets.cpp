#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1); 
        int l = 1;
        int sm = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            l = lcm(l, a[i]);
        }

        for(int i = 1; i <= n; i++) sm += l / a[i];

        
        if(sm < l){
            for(int i = 1; i <= n; i++) cout << l/a[i] << " ";
            cout << "\n";
            continue;
        }
        cout << "-1\n";

    }
}