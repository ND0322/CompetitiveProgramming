#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

char grid[MAXN][MAXN];

int main(){
    int r,c; cin >> r >> c;

    memset(grid,'.', sizeof(grid));

    grid[c-1][0] = 'S';
    grid[c-2][c-1] = 'E';

    for(int i = 1; i < c-1; i++) grid[c-1-i][i] = '#';
    

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cout << grid[i][j];
        cout << "\n";
    }



    

}