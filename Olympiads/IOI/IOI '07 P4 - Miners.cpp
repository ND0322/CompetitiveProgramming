#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e5+5;

int n,dp[2][4][4][4][4], s[MAXN];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        char c; cin >> c;

        if(c == 'M') s[i] = 1;
        if(c == 'B') s[i] = 2;
        if(c == 'F') s[i] = 3;
    }

    for(int i = n-1; i >= 0; i--){
        for(int a = 0; a < 4; a++){
            for(int b = 0; b < 4; b++){
                for(int c = 0; c < 4; c++){
                    for(int d = 0; d < 4; d++){
                        bool x = i & 1;

                        
                        int weight = 2;
                        if(a == b && b == s[i]) weight = 1;
                        if(a != b && b != s[i] && s[i] != a) weight = 3;
                        if(!a && !b) weight = 1;
                        if(!a && b) weight = 1 + (b != s[i]);
            
                        dp[x][a][b][c][d] = dp[x^1][b][s[i]][c][d] + weight;

                        weight = 2;
                        if(c == d && d == s[i] && s[i] == c) weight = 1;
                        if(c != d && d != s[i] && s[i] != c) weight = 3;
                        if(!c && !d) weight = 1;
                        if(!c && d) weight = 1 + (d != s[i]);
                        dp[x][a][b][c][d] = max(dp[x][a][b][c][d], dp[x^1][a][b][d][s[i]] + weight);

                    }
                }
            }
        }
    }

    cout << dp[0][0][0][0][0] << "\n";
}