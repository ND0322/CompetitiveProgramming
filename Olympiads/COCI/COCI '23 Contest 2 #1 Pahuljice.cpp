#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 55;

int n,m;

int grid[MAXN][MAXN];

int check(int x, int y, int dirx, int diry, int use){
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;

    if(grid[x][y] != use) return 0;

    //cout << x << " " << y << "\n";

    return check(x+dirx, y+diry, dirx, diry, use) + 1;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;

            grid[i][j] = (int) c;
        }
    }


    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 43) ans = max(ans, min({check(i-1,j-1,-1,-1, 92), check(i-1,j,-1,0, 124), check(i-1,j+1,-1,1, 47), check(i,j-1,0,-1, 45), check(i,j+1,0,1, 45), check(i+1,j-1,1,-1, 47), check(i+1,j,1,0, 124), check(i+1,j+1,1,1, 92)}));
        }
    }
    
    cout << ans << "\n";

    

}