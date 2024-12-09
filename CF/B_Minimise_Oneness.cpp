#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//f(t) is easy to calculate
//g(t) = 2^n - f(t)

//abs(f(t) - (2^n - f(t)))
//abs(2f(t) - 2^n+1)
//2 - 4 + 1 = 1
//let there be z zeros
//f(t) = 2^z - 1
//abs(2 * (2^z - 1) - 2^n+1)
//abs(2 ^ (z+1) - 2^n - 1)
//need n-1 zeros
//edge case is n = 1

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        for(int i = 0; i < n-1; i++) cout << "0";
        cout << "1\n";
    }
}
