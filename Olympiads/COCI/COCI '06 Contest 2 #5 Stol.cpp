#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 405;

int r, c, psa[MAXN][MAXN];

int main(){
    cin >> r >> c;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            char cel; cin >> cel;

            psa[i][j] = (cel == 'X');
        }
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++) psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    }

    
}