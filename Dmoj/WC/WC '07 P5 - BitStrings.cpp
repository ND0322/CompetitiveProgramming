#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 105;

int cnt[2];

vector<vector<vector<short>>> dp;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int a,b; cin >> a >> b;

        dp = vector<vector<vector<short>>>(n+1, vector<vector<short>>(a+1, vector<short>(b+1,0)));
        for(int i = 1; i <= n; i++){
            string s; cin >> s;

            cnt[0] = cnt[1] = 0;

            for(int j = 0; j < s.size(); j++) cnt[(s[j] == '1')]++;

           

            for(int j = 0; j <= a; j++){
                for(int k = 0; k <= b; k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    
                    if(j - cnt[0] >= 0 && k - cnt[1] >= 0) dp[i][j][k] = max(dp[i][j][k], (short)(dp[i-1][j-cnt[0]][k-cnt[1]]+1));
                    
                }
            }
            
        }

        cout << dp[n][a][b] << "\n";
    }


    
    
}