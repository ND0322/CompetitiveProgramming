#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n, m, r,c;

char ans[MAXN][MAXN];

int main(){
    cin >> n >> m >> r >> c;


    //case 1
    memset(ans,'b', sizeof(ans));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < m; j++) ans[i][j] = 'a';
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < c; j++) ans[i][j] = 'a';
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << ans[i][j];
        cout << "\n";
    }



}