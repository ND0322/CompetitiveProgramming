#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 800;

int n,m, a[MAXN][MAXN], psa[MAXN][MAXN], p[MAXN], s[MAXN];



int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }


    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++) psa[j][i] = psa[j][i-1] + a[i][j];
    }

    for(int i = 1; i <= m; i++){

        memset(p, 0, sizeof(p));
        memset(s,0,sizeof(s));

        
        for(int j = 1; (i-j >= 1) && (i+j <= n)){
            for(int k = 1; k <= n; k++){
                p[k] += a[k][i-j];
                s[k] += a[]
            }
        }
    }
}