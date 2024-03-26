#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n, a[MAXN];

long long dp[MAXN][MAXN];

/*
sort the thing
for any range we gonna add at least a[r] - a[l] + a transition 
*/

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1,a+n+1);

    for(int i = n; i >= 1; i--){
        for(int j = i+1; j <= n; j++) dp[i][j] = a[j]-a[i] + min(dp[i+1][j], dp[i][j-1]);
    }

    cout << dp[1][n] << "\n";
}