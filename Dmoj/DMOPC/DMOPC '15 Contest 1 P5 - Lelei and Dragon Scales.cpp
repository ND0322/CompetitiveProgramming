#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;

int n, m, k, psa[MAXN][MAXN];

int main(){
    cin >> m >> n >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> psa[i][j];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            psa[i][j] += psa[i-1][j];
            psa[i][j] += psa[i][j-1];
            psa[i][j] -= psa[i-1][j-1];
        }
    }


    int ans = 0;
    for(int w = 1; w <= k; w++){
        int l = min(n,k/w);
        for(int i = 1; i <= n-l+1; i++){
            for(int j = 1; j <= m-w+1; j++) ans = max(ans, psa[i+l-1][j+w-1] - psa[i-1][j+w-1] - psa[i+l-1][j-1] + psa[i-1][j-1]);
        }
    }

    cout << ans << "\n";
}