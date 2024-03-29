#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;
const int MOD = 1e9+7;

int n, fib[MAXN], dp[MAXN], psa[MAXN];

/*
dp[i] => answer for length i

from this length we can go from some shorter length and add stuff

for some j we can add dp[i-j] * #number of tails of length j
where a tail is an ending piece with 11

then we need to add the contribution of the tails themselves

2^(i-j) for all possible prefix * possible values of the tail of length j

number of tails is fib[j+1] - fib[j]
possible valaues is sum between [fib(j): fib[j+1])
using arithmetic sum

(fib[j+1]-1 + fib(j))/2 * (fib[j+1] - fib[j])
*/

int main(){
    cin >> n;

    fib[1] = 1;
    for(int i = 2; i <= n+1; i++) fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    

    for(int i = 2; i <= n; i++){
        int pw = 2;
        for(int j = 1; j <= i; j++){
            dp[i] = (dp[i] + dp[i-j] * fib[j+1] - fib[j]) % MOD + pw * ((fib[j+1]-1 + fib[j])%MOD * (fib[j+1] - fib[j]+MOD)%MOD)%MOD;
            pw = (pw<<1)%MOD;
        }
    }

    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << "\n";
}