#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n,k;

int grid[MAXN][MAXN];

int main(){
    //for subtask 1

    cin >> n >> k;

    for(int i = 0; i < n-k; i++){
        grid[n-i-1][n-i-1] = i+1;
    }

    for(int i = 0; i < k; i++){
        grid[i][i] = n*n-i;
    }

    int cnt = n*n-k;

    for(int i = 0; i < n; i++){
        if(!grid[0][i]){
            grid[0][i] = cnt;
            cnt--;
        }
    }

    for(int j = 0; j < n; j++){
        if(!grid[j][0]){
            grid[j][0] = cnt;
            cnt--;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!grid[i][j]){
                grid[i][j] = cnt;
                cnt--;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << grid[i][j] << " ";
        cout << "\n";
    }

    

    

   
}