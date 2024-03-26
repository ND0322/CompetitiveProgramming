#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 105;
const int INF = 1e9/3;

//this question is just floyd warshalls
int z[MAXN], dp[MAXN][MAXN],n;

int main(){
    cin >> n;

    

    for(int i = 0; i <= n; i++){
        int c; cin >> z[i] >> c;

        for(int j = 0; j < c; j++){
            int x; cin >> x;
            dp[i][x] = 1;
            dp[x][i] = 1;
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(!dp[i][j]) dp[i][j] = INF;
            else dp[i][j] = z[j] + 10;
        }
    }

    for(int k = 0; k <= n; k++){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans,dp[0][i] + dp[i][0]);
    }

    cout << ans << "\n";
}

