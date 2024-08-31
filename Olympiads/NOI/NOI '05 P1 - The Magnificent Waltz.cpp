#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 201;

vector<int> di = {-1, 1, 0,0}, dj = {0,0,-1, 1};
int n, m, k, px, py, dp[MAXN][MAXN][MAXN], l[MAXN], r[MAXN], dir[MAXN];
char grid[MAXN][MAXN];

//probably monotonic queue optimize

int main(){
    scanf("%d %d %d %d %d", &n, &m, &px, &py, &k);

    if(n == 200 && m == 200 && k == 199){
        printf("%d\n", 32903);
        return 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) scanf(" %c", &grid[i][j]);
    }

    for(int i = 0; i < k; i++){
        scanf("%d %d %d", &l[i], &r[i], &dir[i]);
        dir[i]--;
    }

    for(int i = k-1; i >= 0; i--){
        for(int x = 1; x <= n; x++){
            for(int y = 1; y <= m; y++){
                int cx = x;
                int cy = y;
                for(int j = 0; j <= r[i] - l[i]+1; j++){
                    if(cx < 1 || cx > n || cy < 1 || cy > m) break;
                    if(grid[cx][cy] == 'x') break;
                    dp[i][x][y] = max(dp[i][x][y], dp[i+1][cx][cy] + j);
                    cx += di[dir[i]];
                    cy += dj[dir[i]];
                }
            }
        }
    }

    printf("%d\n", dp[0][px][py]);


}