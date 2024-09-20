#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long n,k; cin >> n >> k;

        long long sm = ceil(n/(long double)k) * k;

        cout << (long long)ceil(sm / (long double)n) << "\n";

    }
}