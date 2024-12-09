#include <bits/stdc++.h>
#include <iostream>

#define int long long

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);    
}

int lcm(int a, int b){
    return a*b / gcd(a,b);
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b; cin >> a >> b;

        cout << lcm(a,b) << "\n";

    }
}