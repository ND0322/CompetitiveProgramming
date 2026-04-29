#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long
typedef __int128 ij;

const int MAXN = 2005;


int n,m;
ij dp[MAXN][MAXN][2][2], lrow[MAXN][2][5], lcol[MAXN][2][5];

bool grid[MAXN][MAXN];

bitset<MAXN> col[MAXN];

/*
count all paths of length 5 - rectangles

for all paths

dp[i][j][2][5]

pos, last move, current index -> use psa to transition

For rectangles 
*/

int32_t main(){
    cin >> n >> m;;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;

        for(int j = 1; j <= m; j++){
            grid[i][j] = (s[j-1] == '1');
            col[j][i] = (s[j-1] == '1');
        }

    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!grid[i][j]) continue;
            dp[i][j][0][0] = dp[i][j][1][0] = 1;

            lrow[i][0][0]++;
        
            lcol[j][0][0]++;
            lrow[i][1][0]++;
            lcol[j][1][0]++;
        }
    }



    for(int k = 1; k <= 4; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!grid[i][j]) continue;
            
                //0 means use column now
                dp[i][j][0][1] = max((ij)0, lcol[j][1][k-1]-dp[i][j][1][0]);
                dp[i][j][1][1] = max((ij)0, lrow[i][0][k-1]-dp[i][j][0][0]);
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!grid[i][j]) continue;
                lrow[i][0][k] += dp[i][j][0][1];
                lrow[i][1][k] += dp[i][j][1][1];
                lcol[j][0][k] += dp[i][j][0][1];
                lcol[j][1][k] += dp[i][j][1][1];

                dp[i][j][0][0] = dp[i][j][0][1];
                dp[i][j][1][0] = dp[i][j][1][1];
                
            }
        }

    }

    ij ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) ans += dp[i][j][0][0] + dp[i][j][1][0];
    }




    for(int i = 1; i <= m; i++){
        for(int j = i+1; j <= m; j++){
            ij cnt = (col[j] & col[i]).count();
            

            ans -= cnt * (cnt-1) * 4;
        }
    }

    if(!ans) cout << "0\n";

    vector<int> p;
    while(ans){
        p.push_back(ans%10);
        ans /= 10;
    }

    for(int i = p.size()-1; i >= 0; i--) cout << p[i];
    cout << "\n";






}