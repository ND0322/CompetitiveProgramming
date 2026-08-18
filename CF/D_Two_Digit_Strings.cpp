#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, m, a[MAXN], b[MAXN], dp[MAXN][MAXN];



int main(){
    int tt; cin >> tt;

    while(tt--){
        string s,t; cin >> s >> t;

        n = s.size();
        m = t.size();

        for(int i = 1; i <= n+1; i++) a[i] = 0;
        for(int i = 1; i <= m+1; i++) b[i] = 0;
        for(int i = 1; i <= n+1; i++){
            for(int j = 1; j <= m+1; j++) dp[i][j] = 0;
        }

        for(int i = 1; i <= n; i++) a[i] = s[i-1] - '0';
        for(int i = 1; i <= m; i++) b[i] = t[i-1] - '0';

        for(int i = 1; i <= n; i++) a[i] = (a[i] + a[i-1]) % 10;
        for(int i = 1; i <= m; i++) b[i] = (b[i] + b[i-1]) % 10;

        for(int i = n+1; i >= 1; i--){
            for(int j = m+1; j >= 1; j--){
                if(i == n+1 && j == m+1) continue;
                if(i != n+1 && j != m+1 && a[i] == b[j]) dp[i][j] = dp[i+1][j+1] + 1;
                if(i != n+1) dp[i][j] = max(dp[i][j], dp[i+1][j]);
                if(j != m+1) dp[i][j] = max(dp[i][j], dp[i][j+1]);
            }
        }

        if(a[n] != b[m]){
            cout << "-1\n";
            continue;
        }

        cout << dp[1][1] << "\n";


        
        
    }
}