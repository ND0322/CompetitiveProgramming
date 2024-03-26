#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;
const int long long INF = 1e14;

typedef long long ll;


int n,cost[MAXN],draw[MAXN];

ll dp[MAXN][MAXN];

//ind, drawn

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> cost[i] >> draw[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = INF;
    }

    dp[n][n-1] = 0;

    

    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){

            if(i > j) continue;
            dp[i][j] = min(dp[i+1][j],dp[i+1][min(j+draw[i],n-1)] + cost[i]);

            //cout << i << " " << j << "\n";

            //cout << dp[i+1][j] << " " << dp[i+1][min(j+draw[i],n-1)] + cost[i] << "\n";
        }
    }



    cout << dp[0][0] << "\n";
}