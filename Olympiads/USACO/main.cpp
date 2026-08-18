#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e4+5;

#define int long long

int n, dp[2005][MAXN], MOD;

bool prime[MAXN];

/*
cycle lengths sum to n

lcm of cycle lengths = k
use only primes to construct

number of k that can be formed such that sum of prime factors <= n
*/

int32_t main(){
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    cin >> n >> MOD;

    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i * i <= n; i++){
        if(prime[i]){
            for(int j = i*i; j <= n; j += i) prime[j] = 0;
        }
    }


    vector<int> a;

    a.push_back(0);

    for(int i = 1; i <= n; i++){
        if(prime[i]) a.push_back(i);
    }

    for(int i = 0; i <= n; i++) dp[(int)a.size()][i] = 1;

    for(int i = a.size()-1; i >= 1; i--){
        for(int j = 0; j <= n; j++){
            int take = a[i];

            dp[i][j] = dp[i+1][j];

            
            while(take <= j){
                dp[i][j] = (dp[i][j] + (dp[i+1][j-take] * take) % MOD) % MOD;
                take *= a[i];
            }
        }
    }

    cout << dp[1][n] << "\n";
}