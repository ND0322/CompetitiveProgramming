#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3005;

int n;

double a[MAXN], dp[MAXN][MAXN];

int main(){

    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;


    for(int i = 0; i < n; i++) cin >> a[i];

    int big = n/2+1;

    for(int i = 0; i <= n; i++) dp[i][big] = 1;

    for(int i = n-1; i >= 0; i--){
        for(int j = big-1; j >= 0; j--){
            dp[i][j] = a[i] * dp[i+1][j+1] + (1-a[i]) * dp[i+1][j];
        }
    }

    cout << setprecision(10) << fixed << dp[0][0] << "\n";
}