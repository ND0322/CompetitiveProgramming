#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 755;

int n, a[MAXN][MAXN], dp[MAXN][MAXN];

int main(){
    cin >> n;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++) cin >> a[j][i];
    }

    for(int i = 1; i < n; i++) dp[i][i+1] = a[i][i+1];

    for(int i = n; i >= 1; i--){
        for(int j = i+2; j <= n; j++){
            //rooted at i
            dp[i][j] = 1e9;
            for(int k = i; k < j; k++)dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i][k+1]);
        }
    }

    cout << dp[1][n] << "\n";
}

/*
each i will contain a contignous subarray 
*/