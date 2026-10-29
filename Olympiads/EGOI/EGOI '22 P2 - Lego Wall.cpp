#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;
const int MOD = 1e9+7;


int n,m;

vector<vector<int>> dp0, dp1, dp2;

/*
for h = 2

A good structure needs a two piece in at least one row of each 2 length subarray 

Complementary count number of bad structures

dp w and h

We can iterate over w and split the current grid into two halves


*/

int main(){
    cin >> m >> n;

    dp0 = vector<vector<int>>(n+5, vector<int> (m+5));
    dp1 = vector<vector<int>>(n+5, vector<int> (m+5));
    dp2 = vector<vector<int>>(n+5, vector<int> (m+5));


    if(m <= n){

        dp0[1][0] = 1;
        for(int j = 1; j <= m; j++) dp0[1][j] = (dp0[1][j-1] + (j >= 2 ? dp0[1][j-2] : 0)) % MOD;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= m; j++) dp0[i][j] = (dp0[i-1][j] * dp0[1][j]) % MOD;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= j; k++) dp1[]
            }
        }

        cout << good[n][m] << "\n";

        cout << good[n][m] - dp[n][m] << "\n";
    }
    else{

    }

}