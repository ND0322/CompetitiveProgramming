#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, k, dp[MAXN][5], a[MAXN][2];

//i, some cases
/*
0 for none
1 for only top
2 for only bottom
3 for both top and bottom seperate
4 for both at a time

*/


int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i][0];
    for(int i = 1; i <= n; i++) cin >> a[i][1];

    for(int i = n; i >= 1; i--){
        //kill all rows
        dp[i][0] = dp[i+1][0] + a[i][0] + a[i][1];
        dp[i][1] = dp[i+1][0] + a[i][0] + a[i][1];
        dp[i][2] = dp[i+1][0] + a[i][0] + a[i][1];
        dp[i][3] = dp[i+1][0] + a[i][0] + a[i][1];
        dp[i][4] = dp[i+1][0] + a[i][0] + a[i][1];

        //kill all start new stuff
        dp[i][0] = max({dp[i][0], dp[i+1][1] + k + a[i][1], dp[i+1][2] + k + a[i][0], dp[i+1][3] + 2*k, dp[i+1][4] + k});
        dp[i][1] = max({dp[i][1], dp[i+1][1] + k + a[i][1], dp[i+1][2] + k + a[i][0], dp[i+1][3] + 2*k, dp[i+1][4] + k});
        dp[i][2] = max({dp[i][2], dp[i+1][1] + k + a[i][1], dp[i+1][2] + k + a[i][0], dp[i+1][3] + 2*k, dp[i+1][4] + k});
        dp[i][3] = max({dp[i][3], dp[i+1][1] + k + a[i][1], dp[i+1][2] + k + a[i][0], dp[i+1][3] + 2*k, dp[i+1][4] + k});
        dp[i][4] = max({dp[i][4], dp[i+1][1] + k + a[i][1], dp[i+1][2] + k + a[i][0], dp[i+1][3] + 2*k, dp[i+1][4] + k});

        
        

    }
}