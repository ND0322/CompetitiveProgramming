#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 3e5+5;

int dp[MAXN][2];

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int n =s.size();

        s = "." + s;

        for(int i = 0; i <= n+1; i++) dp[i][0] = dp[i][1] = 0;
        


        for(int i = n; i >= 1; i--){
            //1 for if we've taken a 1 or 3

            if(s[i] == '4'){
                dp[i][0] = dp[i+1][0] + 1;
                dp[i][1] = dp[i+1][1] + 1;
                continue;
            }

            if(s[i] == '2'){
                dp[i][1] = dp[i+1][1] + 1;
                dp[i][0] = dp[i+1][0];
                continue;
            }

            dp[i][0] = min(dp[i+1][0] + 1, dp[i+1][1]);
            dp[i][1] = dp[i+1][1];

        }

        cout << dp[1][0] << "\n";
        


        
    }
}