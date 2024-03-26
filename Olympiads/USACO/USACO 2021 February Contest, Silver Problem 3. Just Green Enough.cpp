#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;

int n, table[4][MAXN][4][MAXN];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> table[0][i][0][j];
            
            for(int k = 1; k <= log2(n); k++){
                for(int l = 0; l + (1<<(k-1)) < n; l++) table[0][i][k][j] = min(table[0][i][k-1][j], table[0][i][k-1][l+(1<<(k-1))]);
            }
            
        }
    }

    for(int j = 0; j <= log(n); j++){
        for(int i = 0; i < n; i++){
            for(int k = 0; k <= log(n); k++){
                for(int l = 0; l < n; l++) table[j][i][k][l] = min(table[j-1][i][k][l], table[j-1][i+(1<<(j-1))][k][l]);
            }
        }
    }


    
}        
