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
    long long n; cin >> n;

    if(n == 1){
        cout << "1\n";
        return 0;
    }

    if(n == 2){
        cout << "2\n";
        return 0;
    }

    if(n == 3){
        cout << "6\n";
        return 0;
    }

    if(n&1){
        cout << n * (n-1) * (n-2) << "\n";
        return 0;
    }

    long long ans = 0;
    for(long long i = max(n-100,0LL); i <= n; i++){
        for(long long j = i; j <= n; j++){
            for(long long k = j; k <= n; k++) ans = max(ans, (long long)lcm(i, (long long)lcm(j,k)));
        }
    }

    cout << ans << "\n";
}