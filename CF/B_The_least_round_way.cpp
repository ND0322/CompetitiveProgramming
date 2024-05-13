#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n, a[MAXN][MAXN], dp[MAXN][MAXN][20];

bool rebuild[MAXN][MAXN][20];

int solve(int i, int j, int x){
    if(x < 0) return 1e9;
    if(i == n && j == n) return (!x ? 0 : 1e9);

    if(dp[i][j][x] == -1){
        int opt1 = 1e9;
        int opt2 = 1e9;

        if(i+1 <= n && j){
            int five = 0;
            int cur = a[i+1][j];

            while(cur % 5 == 0){
                five++;
                cur/=5;
            }

            int two = 0;
            cur = a[i+1][j];

            while(!(cur & 1)){
                two++;
                cur>>=1;
            }

            opt1 = solve(i+1,j, x-five) + two;
        }

        if(j+1 <= n && i){
            int five = 0;
            int cur = a[i][j+1];

            while(cur % 5 == 0){
                five++;
                cur/=5;
            }

            int two = 0;
            cur = a[i][j+1];

            while(!(cur & 1)){
                two++;
                cur>>=1;
            }

            opt2 = solve(i,j+1, x-five) + two;
        }


        dp[i][j][x] = min(opt1,opt2);
        if(dp[i][j][x] == -1) dp[i][j][x] = 1e9;    
        if(opt1 < opt2) rebuild[i][j][x] = 0;
        else rebuild[i][j][x] = 1;
    }
    return dp[i][j][x];
}


int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    
    memset(dp,-1,sizeof(dp));

    int ans = 1e9;
    int opt = -1;

    for(int i = 0; i <= 10; i++){
        solve(0,1,i);
        if(dp[0][1][i] == -1) continue;
        ans = min(ans, min(i, dp[0][1][i]));
        if(ans == min(i, dp[0][1][i])) opt = i;
    }

    string res;
    int x = 0;
    int y = 1;
    int k = 0;

    while(x != n || y != n){

        if(rebuild[x][y][k] == 0){
            x++;
            res += 'D';

            int five = 0;
            int cur = a[x][y];

            while(cur % 5 == 0){
                five++;
                cur/=5;
            }

            k += five;
        }
        else{
            y++;
            res += 'R';
            int five = 0;
            int cur = a[x][y];

            while(cur % 5 == 0){
                five++;
                cur/=5;
            }

            k += five;
        }
    }

    cout << ans << "\n";
    for(int i = 1; i < n+2; i++) cout << res[i];


}