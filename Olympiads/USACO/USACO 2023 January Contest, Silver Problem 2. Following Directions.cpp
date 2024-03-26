#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use dp to count the number of cows going through each cell
//update by reverting one path, switching the direction, then adding to the path again.

const int MAXN = 1505;

bool grid[MAXN][MAXN];

int n,q, a[MAXN], b[MAXN], dp[MAXN][MAXN];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;

            grid[i][j] = (c=='R');
        }

        cin >> a[i];
    }

    for(int i = 0; i < n; i++) cin >> b[i];

    

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){

            if(i != n && j != n) dp[i][j] = 1;
            if(i && j != n && !grid[i-1][j]) dp[i][j] += dp[i-1][j];
            if(i != n && j && grid[i][j-1]) dp[i][j] += dp[i][j-1];
        }
    }

    //for(int i = 0; i <= n; i++){
        //for(int j = 0; j <= n; j++) cout << dp[i][j] << " ";
        //cout << "\n";
    //}

    int ans = 0;
    for(int i = 0; i < n; i++) ans += dp[i][n] * a[i] + dp[n][i] * b[i];
    cout << ans << "\n";

    cin >> q;

    while(q--){
        int x,y; cin >> x >> y;

        x--;
        y--;

        int tmp = dp[x][y];

        int cx = x;
        int cy= y;

        while(1){
            dp[cx][cy] -= tmp;
            if(cx == n || cy == n) break;
            if(grid[cx][cy]) cy++;
            else cx++;
        }

       

        
        
        grid[x][y] ^= 1;

        cx = x;
        cy= y;

        while(1){
            dp[cx][cy] += tmp;
            if(cx == n || cy == n) break;
            if(grid[cx][cy]) cy++;
            else cx++;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) ans += dp[i][n] * a[i] + dp[n][i] * b[i];
        cout << ans << "\n";


    }




}