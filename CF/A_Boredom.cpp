#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, freq[MAXN];

long long dp[MAXN];

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    dp[1] = freq[1];

    for(int i = 2; i < MAXN; i++) dp[i] = max(dp[i-1], dp[i-2] + freq[i] * i);
    cout << dp[MAXN-1] << "\n";
}