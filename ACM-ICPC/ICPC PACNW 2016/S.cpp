#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n, m, best[55][55];

char grid[55][55];

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
           
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != 'o') continue;

            if(i == n-1){
                continue;
            }

            grid[i][j] = '.';

            bool flag = 1;

            for(int k = i; k < n-1; k++){
                if(grid[k+1][j] != '.'){
                    grid[k][j] = 'o';
                    flag = 0;
                    break;
                }
            }

            if(flag && grid[n-1][j] == '.'){
                grid[n-1][j] = 'o';
            }
        }
    }   

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
