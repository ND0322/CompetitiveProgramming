#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;


    while(tt--){
        bool flag = false;

        vector<string> grid(3);

        cin >> grid[0];
        cin >> grid[1];
        cin >> grid[2];

        if(grid[0][0] != '.' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
            cout << grid[0][0] << "\n";
            continue;
        }
        if(grid[0][2] != '.' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
            cout << grid[0][2] << "\n";
            continue;
        }

        for(int i =0; i < 3; i++){
            if(grid[i][0] != '.' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){
                cout << grid[i][0] << "\n";
                flag = true;
                break;
            }

            if(grid[0][i] != '.' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]){
                cout << grid[0][i] << "\n";
                flag = true;
                break;
            }
        }

        if(!flag){
            cout << "DRAW\n";
        }

        


    }
}