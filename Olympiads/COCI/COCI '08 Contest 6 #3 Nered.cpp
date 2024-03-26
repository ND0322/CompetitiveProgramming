#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int n, m, psa[MAXN][MAXN];



int main(){
    cin >> n >> m;

    int ans = 0;
    int best = 1e9;
    int tot = m;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        if(psa[x][y]){
            ans++;
            tot--;
        }
        psa[x][y] = 1;
    }

    //easy to convert to n^3

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int x = i; x <= n; x++){
                for(int y = j; y <= n; y++){
                    if((y-j+1) * (x-i+1) != m) continue;
                    //cout << i << " " << j << " " << x << " " << y << " " << psa[x][y] - psa[i-1][y] - psa[x][j-1] + psa[i-1][j-1] << "\n";
                    best = min(best, tot - (psa[x][y] - psa[i-1][y] - psa[x][j-1] + psa[i-1][j-1]));
                }
            }
        }
    }

    cout << best+ans << "\n";
}