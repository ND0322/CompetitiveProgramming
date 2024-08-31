#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n, x[MAXN], y[MAXN], dp[MAXN][MAXN];

/*
dp[i][j] => person a is at i-1 position b is at jth position
*/

/*
for sample
move b, + 2
move a, + 1
move b, + 3
*/

int main(){
    cin >> n;

    if(n == 0) cout << "YES\n";

    cin >> x[1] >> y[1] >> x[2] >> y[2];

    for(int i = 3; i <= n+2; i++) cin >> x[i] >> y[i];

    for(int i = n+2; i >= 3; i--){
        for(int j = 1; j < i; j++){
            if(i == 3){
                dp[i][j] = min(dp[i+1][1] + abs(x[i] - x[2]) + abs(y[i] - y[2]), dp[i+1][2] + abs(x[i] - x[1]) + abs(y[i] - y[1]));
                continue;
            }
            dp[i][j] = dp[i+1][j] + abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
            dp[i][j] = min(dp[i][j], dp[i+1][i-1] + abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
    }

    if(!min(dp[3][1], dp[3][2])) cout << n << "\n";

    cout << min(dp[3][1], dp[3][2]) << "\n";

    
}