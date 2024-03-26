#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 55;

int n,m;
char grid[MAXN][MAXN];

bool visited[MAXN][MAXN];

void dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || grid[x][y] == 'W') return;

    visited[x][y] = 1;

    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);



    
    
}

int main(){
    cin >> n >> m;

    bool check = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];

            check &= (grid[i][j] != 'L');
        }
    }

    if(check){
        cout << "0\n";
        return 0;
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 'L'){
                ans++;
                dfs(i,j);
            }
        }
    }

    cout << ans << "\n";


}