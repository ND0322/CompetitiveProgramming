#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n,m;

bool yes[1005][1005], vis[1005][1005];


void dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || !yes[x][y]) return;

    vis[x][y] = true;

    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y-1);
    dfs(x-1,y+1);
    dfs(x+1,y-1);
    dfs(x+1,y+1);

    
}
    
     

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string s; cin >> s;

        for(int j = 0; j < m; j++){
            if(s[j] == '#') yes[i][j] = true;
        }
    }

    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && yes[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
    }

    cout << cnt << "\n";
}