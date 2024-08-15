#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], dp[MAXN][15];
//uppr bound of the answer is n - number of ai = 0
//process both rows at once
//either skip this one
//or cover the suffix and check the overlap
//span for squares is at most 4 rows
//we should just use operation 2 on any rows with greater than 4 prefix cause it doesnt save time
//im bald we can just keep a bitmask 
int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i < 16; i++) dp[0][i] = 1e9;
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 16; j++){

                int opt = 0;

                int mn = 5;
                int mx = -1;

                for(int k = 8; k >= 1; k>>=1){
                    if(j & k){
                        mn = min(mn,k);
                        mx = max(mx, k);
                    }
                }

                if(mn == 5) opt = 0;
                else opt = (log2(mx)-log2(mn) > 1) + 1;
                dp[i][j] = dp[i-1][0] + (bool)a[i] + opt;

                //can place left right middle or 2
                if(a[i] > 4) continue;

                int nxt = (1<<a[i]) - 1;
                if(opt == 1){
                    nxt -= mn * (bool)(nxt & mn);
                    nxt -= mn*2 * (bool)(nxt & (mn*2));
                }
                if(opt == 2) nxt = 0;

                //cout << i << " " << opt << " " << bitset<4>(j) << " " << bitset<4>(nxt) << " " << dp[i-1][nxt] + opt << "\n";

                dp[i][j] = min(dp[i][j], dp[i-1][nxt] + opt);



                
            }

            

        }

        cout << dp[n][0] << "\n";
    }
}

/*
0111
0011
0001
0000
*/