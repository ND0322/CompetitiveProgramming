#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN = 18;

int n;

double dp[1<<MAXN], a[MAXN][MAXN];

//dp[i] => probability of that mask

double solve(int i, int mask){
    if(i == n) return 1;

    if(dp[mask] == -1.0){
        dp[mask] = 0;
        for(int j = 0; j < n; j++){
            if(!(mask & (1<<j))) continue;

            for(int k = 0; k < n; k++){
                if(mask & (1<<k)) continue;

                dp[mask] += 1/((i+1)*i/2.0) * a[j][k] * solve(i+1,mask^(1<<k));
            }
        }
    }
    return dp[mask];
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    for(int i = 0; i < (1<<n); i++) dp[i] = -1;

    for(int i = 0; i < n; i++) cout << setprecision(6) << fixed << solve(1, 1<<i) << " ";
    cout << "\n";

}