#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 50;

int n, grid[MAXN][MAXN];

int main(){
    cin >> n;
    int x = 0;
    int y = 0;
    int cnt = 1;

    while(x != (n+1)/2 || y != (n+1)/2){
        grid[x][y] = cnt++;
        y++;

        if(y == n){
            x++;
            y=0;
        }
        
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << grid[i][j] << " ";
        cout << "\n";
    }
}


