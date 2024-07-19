#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int msb(long long x){
    return 64-__builtin_clzll(x);
}

int main(){
    int tt; cin >> tt;

    //1 0 0 1
    while(tt--){
        long long n; cin >> n;

        if(__builtin_popcountll(n) == 1){
            cout << "1\n";
            cout << n << "\n";
            continue;
        }
        cout << __builtin_popcountll(n) + 1 << "\n";

        for(long long i = (1LL<<msb(n)); i > 0; i >>= 1){
            if(n & i) cout << n - i << " ";
        }

        cout << n << "\n";
    }
}