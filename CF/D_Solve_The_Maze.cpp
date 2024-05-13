#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 55;

int n, m; 

char grid[MAXN][MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        //block off all neighbors of bad

        cin >> n >> m;

        for(int i = 1; i <= n; i++) grid[i][0] = grid[i][m+1] = '#';
        for(int i = 1; i <= m; i++) grid[0][i] = grid[n+1][i] = '#';


        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) cin >> grid[i][j];
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(grid[i][j] == 'B'){
                    if(grid[i+1][j] == '.') grid[i+1][j] = '#';
                    if(grid[i-1][j] == '.') grid[i-1][j] = '#';
                    if(grid[i][j+1] == '.') grid[i][j+1] = '#';
                    if(grid[i][j-1] == '.') grid[i][j-1] = '#';
                }
            }
        }

        
    }
}