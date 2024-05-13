#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int a,b,c;

double dp[MAXN][MAXN][MAXN];

double solve(int x,int y,int z){
    if(x > a || y > b || z > c) return 0.0;
    if(x == a && y == b && z == c) return 1.0;

    if(dp[x][y][z] == -1){
        dp[x][y][z] = 0;
        dp[x][y][z] += solve(x+1,y,z) * ((x+1) * z)/(double)((x+y+z+1)*(x+y+z));
        dp[x][y][z] += solve(x,y+1,z) * ((y+1) * x)/(double)((x+y+z+1)*(x+y+z));
        dp[x][y][z] += solve(x,y,z+1) * ((z+1) * y)/(double)((x+y+z+1)*(x+y+z));

        
    }
    return dp[x][y][z];
}

int main(){
    cin >> a >> b >> c;

    memset(dp,-1,sizeof(dp));

    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= c; k++) dp[i][j][k] = -1;
        }
    }

    double ans = 0;

    
    for(int i = 1; i <= a; i++){
        ans += solve(i, 0, 0);
        cout << solve(i,0,0) << "\n";
    }


    cout << ans << " ";
}