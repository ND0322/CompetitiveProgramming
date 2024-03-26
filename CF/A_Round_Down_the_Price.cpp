#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long x; cin >> x;

        long long ans = 1;
        long long balls = floor(log10(x));
        while(balls--)ans*=10;

        cout << x - ans << "\n";
    }
}