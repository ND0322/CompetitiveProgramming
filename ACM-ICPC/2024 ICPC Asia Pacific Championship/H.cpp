#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, dp[MAXN][2][2];




int main(){
    cin >> n;

    memset(dp, 0x3f, sizeof(dp));

    int tot = 0;
    int tt = 0;

    for(int i = 1 ; i <= n; i++){
        string s; cin >> s;

        int cnt = 0;

        for(int j : s) cnt += (j == '1');

        tot += cnt;
        tt += (int)s.size();

        if(i == 1){
            dp[i][1][0] = cnt;
            dp[i][0][1] = (int)s.size() - cnt;
            continue;
        }

        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                dp[i][1][k] = min(dp[i][1][k], dp[i-1][j][k] + cnt);
                dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][k] + (int)s.size() - cnt);
            }
        }
    }

    if(tot == tt || tot == 0){
        cout << "0\n";
        return 0;
    }

    cout << dp[n][1][1] << "\n";
}