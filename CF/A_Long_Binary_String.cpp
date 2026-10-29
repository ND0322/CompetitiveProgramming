#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
number of ones in each block is fib
find the left and right blocks of fib
for the end caps its a little hard 
*/

const int MAXN = 3e5+5;

int q, psa[MAXN];

long long dp[105];




int main(){

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= 87; i++) dp[i] = dp[i-1] + dp[i-2];


    cin >> q;

    while(q--){
        long long l,r; cin >> l >> r;

        if(l == 1 && r == 1){
            cout << "1\n";
            continue;
        }

        long long sr = 0;
        long long sl = 0;
        l--;

        for(int i = 87; i >= 1; i--){
            if(r >= dp[i]){
                r -= dp[i];
                sr += dp[i-1];
            }
            if(l >= dp[i]){
                l -= dp[i];
                sl += dp[i-1];
            }
        }

        cout << sr - sl << "\n";

        
    }



}