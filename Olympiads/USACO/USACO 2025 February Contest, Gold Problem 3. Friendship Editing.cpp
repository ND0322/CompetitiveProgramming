#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 17;

int n,m, dp[1<<MAXN];

bool adj[MAXN][MAXN];
int main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) adj[i][j] = !adj[i][j];
    }

    for(int i = 0; i < )
}