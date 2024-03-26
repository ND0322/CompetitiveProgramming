#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//3d floodfill 
//bruteforce pull direction

const int MAXN = 15;

int n;

char grid[MAXN][MAXN][MAXN];

bool vis[MAXN][MAXN][MAXN];

void dfs(int x, int y, int z, int dir[4]){
    if(vis[x][y][z]) return;

    vis[x][y][z] = 1;

    if(grid[x][y][z] == grid[x+1][y][z]) dfs(x+1,y,z,dir);
    if(grid[x][y][z] == grid[x-1][y][z])dfs(x-1,y,z,dir);
    if(grid[x][y][z] == grid[x][y+1][z])dfs(x,y+1,z,dir);
    if(grid[x][y][z] == grid[x][y-1][z])dfs(x,y-1,z,dir);
    if(grid[x][y][z] == grid[x][y][z+1])dfs(x,y,z+1,dir);
    if(grid[x][y][z] == grid[x][y][z-1])dfs(x,y,z-1,dir);
    if(grid[x+dir[0]][y+dir[1]][z+dir[2]]) dfs(x+dir[0],y+dir[1],z+dir[2],dir);
}

void solve(){
   

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++) cin >> grid[i][j][k];
        }

    }

    for(int i = 1; i <= n; i++){
        for(int j= 1; j <= n; j++){
            for(int k = 1; k <= n; k++) cout << grid[i][j][k];
            cout << "\n";
        }

        cout << "\n";
    }

    if(n == 1){
        cout << "Yes\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 0; l < 4; l++){

                    
                    memset(vis,0,sizeof(vis));
                    int d[4] = {0,0,0,0};
                    d[l] = 1;

                    if(!grid[i + d[0]][j+d[1]][k+d[2]]){
                        dfs(i,j,k,d);
                        bool flag = 1;
                        for(int x = 1; x <= n; x++){
                            for(int y = 1; y <= n; y++){
                                for(int z = 1; z <= n; z++) flag &= vis[x][y][z];
                            }
                        }

                        if(flag){
                            cout << i << " " << j << " " << k << " " << l << "\n";
                            cout << "No\n";
                            return;
                        }
                    }

                    memset(vis,0,sizeof(vis));
                    d[0] = 0;
                    d[1] = 0;
                    d[2] = 0;
                    d[3] = 0;
                    d[l] = -1;
                    if(!grid[i + d[0]][j+d[1]][k+d[2]]){
                        dfs(i,j,k,d);
                        bool flag = 1;
                        for(int x = 1; x <= n; x++){
                            for(int y = 1; y <= n; y++){
                                for(int z = 1; z <= n; z++) flag &= vis[x][y][z];
                            }
                        }

                        if(flag){
                            cout << i << " " << j << " " << k << " " << l << "\n";
                            cout << "No\n";
                            return;
                        }
                    }
                }
            }
            
        }

        
    }

    cout << "Yes\n";
}

int main(){
    while(1){
        cin >> n;

        if(!n) return 0;

        solve();
    }
}

/*
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//3d floodfill 
//bruteforce pull direction

const int MAXN = 15;

int n;

char grid[MAXN][MAXN][MAXN];

bool vis[MAXN][MAXN][MAXN];

void dfs(int x, int y, int z, int dirx, int diry, int dirz){
    if(x <= 0 || x > n || y <= 0 || y > n || z <= 0 || z > n) return;
    if(vis[x][y][z]) return;

    vis[x][y][z] = 1;

    dfs(x+1,y,z,dirx, diry, dirz);
    dfs(x-1,y,z,dirx, diry, dirz);
    dfs(x,y+1,z,dirx, diry, dirz);
    dfs(x,y-1,z,dirx, diry, dirz);
    dfs(x,y,z+1,dirx, diry, dirz);
    dfs(x,y,z-1,dirx, diry, dirz);
    dfs(x+dirx,y+diry,z+dirz, dirx,diry,dirz);
}

void solve(){
   

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++) cin >> grid[i][j][k];
        }

    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++) cout << grid[i][j][k];
            cout << "\n";
        }

        cout << "\n";
    }
}

int main(){
    while(1){
        cin >> n;

        cout << n << "\n";

        if(!n) return 0;

        solve();
    }
}
*/