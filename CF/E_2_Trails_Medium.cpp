#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1e9+7;

#define int long long

int m, n, a[105], b[105], dp[1005][105];


struct matrix {
    long long mat[105][105];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 1; i <= m; i++) {
          for (int j = 1; j <= m; j++) {
              c.mat[i][j] = 0;
              for (int k = 1; k <= m; k++) {
                  c.mat[i][j] = (c.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % MOD) % MOD;
              }
          }
        }
        return c;
    }
};

matrix matpow(matrix base, long long n) {
    matrix ans;

    for(int i = 1; i <= m; i++) ans.mat[i][i] = 1;
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}


int32_t main(){
    cin >> m >> n;

    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    



    matrix mat;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            mat.mat[i][j] = ((a[i] * b[j]) % MOD + (b[i] * a[j]) % MOD + (a[i] * a[j]) % MOD) % MOD;
        }
    }

    matrix ans = matpow(mat, n);

    long long result = 0;
    for(int j = 1; j <= m; j++){
        result = (result + ans.mat[1][j]) % MOD; 
    }
    cout << result << "\n";

}