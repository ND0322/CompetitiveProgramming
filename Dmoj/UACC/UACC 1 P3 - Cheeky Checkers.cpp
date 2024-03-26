#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char grid[9][9];

vector<int> di = {1,1,-1,-1};
vector<int> dj = {1,-1,1,-1};


//backtracking

int ans = 0;

void dfs(int x, int y, int d, bool start = 1){
    if(x < 0 || x >= 8 || y < 0 || y >= 8) return;
    if(grid[x][y] != '.' && !start) return;
    ans = max(ans,d);


    for(int i = 0; i < 4; i++){
        int cx = x+di[i];
        int cy = y+dj[i];

        if(cx < 0 || cx >= 8 || cy < 0 || cy >= 8) continue;

        if(grid[cx][cy] != 'B') continue;

        grid[cx][cy] = '.';

        dfs(cx+di[i], cy+dj[i], d+1, 0);
        grid[cx][cy] = 'B';
    }





}

int main(){
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) cin >> grid[i][j];
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(grid[i][j] == 'A') dfs(i,j,0);
        }
    }

    cout << ans << "\n";



}

/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/