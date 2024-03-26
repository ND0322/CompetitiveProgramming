#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    return !b ? a : gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long a,b,m; cin >> a >> b >> m;

        long long ans = 2;
        long long tmp = lcm(a,b);

        m += tmp;

        ans += m/a - tmp/a;
        ans += m/b - tmp/b;

        cout << ans << "\n";




    }
}