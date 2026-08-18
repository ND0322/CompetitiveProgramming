#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;
const int MAXM = 505;

int n, m, l;

char a[MAXN];


bitset<MAXM> dp[MAXN][MAXM], grid[MAXM];

map<char, int> mp = {{'N',0}, {'W', 1}, {'S', 2}, {'E', 3}};

vector<int> di = {-1, 0, 1, 0}, dj = {0, -1, 0, 1};

int main(){
    cin >> n >> m >> l;

    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;

            grid[i][j] = (c == '.');
        }
    }



    for(int i = 1; i <= l; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) dp[1][i][j] = grid[i][j];
    }

    
    for(int k = 1; k <= l; k++){
        for(int i = 1; i <= n; i++){
            dp[k][i] &= grid[i];

            if(a[k] == 'W' || a[k] == '?') dp[k+1][i] |= dp[k][i] >> 1;
            if(a[k] == 'E' || a[k] == '?') dp[k+1][i] |= dp[k][i] << 1;
            if(a[k] == 'N' || a[k] == '?') dp[k+1][i-1] |= dp[k][i];
            if(a[k] == 'S' || a[k] == '?') dp[k+1][i+1] |= dp[k][i];
        }
    }
    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) ans += dp[l+1][i][j] & grid[i][j];
    }

    cout << ans << "\n";
    
    

    
}