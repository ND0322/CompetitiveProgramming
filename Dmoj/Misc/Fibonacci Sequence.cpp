#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int unsigned long long

const int MOD = 1e9+7;


void mult(int F[2][2], int M[2][2]){
    int x = ((F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD) % MOD;
    int y = ((F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD) % MOD;
    int z = ((F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD) % MOD;
    int w = ((F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD) % MOD;
 
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n){
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{ 1, 1 }, { 1, 0}};
 
    power(F, n / 2);
    mult(F, F);
 
    if (n % 2 != 0)
        mult(F, M);
}



int32_t main(){
    int n; cin >> n;

    int F[2][2] = {{ 1, 1 }, { 1, 0 } };
    if (n == 0){
        cout << "0\n";
        return 0;
    }
    power(F, n - 1);
    cout << F[0][0] << "\n";
}