#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, dp[MAXN][MAXN];

string s;


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> s;

        n = s.size();

        s = '_' + s;

        int ans = 0;

        for(int i = 1; i <= n+1; i++){
            for(int j = 1; j <= n+1; j++) dp[i][j] = 0;
        }

        for(int i = n; i >= 1; i--){
            for(int j = n; j >= 1; j--){
                if(s[i] == s[j] || s[i] == '?' || s[j] == '?') dp[i][j] = dp[i+1][j+1] + 1;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][j] >= (j-i)) ans = max(ans, (j-i) * 2);
            }
        }

        cout << ans << "\n";

       
    }
}