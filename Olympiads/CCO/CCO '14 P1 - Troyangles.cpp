#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n,dp[MAXN][MAXN];

bool t[MAXN][MAXN];

int solve(int x, int y){
    if(!t[x][y]) return 0;

    if(dp[x][y] == -1){
        dp[x][y] = min({solve(x + 1, y - 1), solve(x + 1, y), solve(x + 1, y + 1)}) + 1;
    }
    return dp[x][y];
}

int main(){
    cin >> n;

    long long ans = 0;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;

        for(int j = 0; j < n; j++){
            t[i][j+1] = (s[j] == '#');

            
        }
    }

    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= n+1; j++){
            dp[i][j] = -1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(t[i][j]){
                ans += solve(i,j);
            }
        }
    }

    cout <<ans << "\n";


}