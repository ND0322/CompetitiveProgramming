#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 755;

int n, m, l[MAXN][MAXN][2];

bool a[MAXN][MAXN];

//for each cell find the maximum diagonal in each direction then makes bruteforces faster 

int main(){
    cin >> n >> m;

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 1; j <= m; j++) {
            a[i][j] = (s[j-1] == '1');
            cnt += a[i][j];
        }
    }

   
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            for(int k = 0; k <= n+m; k++){
                if(i + k > n || j-k <= 0) break;
                if(!a[i+k][j-k]) break;
                l[i][j][0] = k+1;
            }

            for(int k = 0; k <= n+m; k++){
                if(i + k > n || j+k > m) break;
                if(!a[i+k][j+k]) break;
                l[i][j][1] = k+1;
            }
        }
    }

    int ans = (bool)cnt;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k < min(l[i][j][0], l[i][j][1]); k++){
                if(l[i+k][j-k][1] >= k+1 && l[i+k][j+k][0] >= k+1) ans = max(ans, k+1);
            }
        }
    }

    cout << ans << "\n";

    



}