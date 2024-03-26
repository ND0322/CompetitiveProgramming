#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long a,b; cin >> a >> b;

        if(a == 1) cout << b*b << "\n";
       
        long long lcm = (a*b)/gcd(a,b);

        if(lcm == b) cout << b*b/a;
        else cout << lcm << "\n";
    }
}