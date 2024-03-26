#include <bits/stdc++.h>
#include <iostream>


using namespace std;


short n,k;

short c;

vector<long long> dp[205][55];

pair<int,int> stuffs[205];

int main(){
    cin >> n >> c >> k;
    
    short i;
    short j;
    short l;

    for(i = 1; i <= n; i++) cin >> stuffs[i].first >> stuffs[i].second;

    sort(stuffs+1, stuffs+n+1);
    
    for(i = 0; i <= n+1; i++){
        for(j = 0; j <= k; j++) dp[i][j] = vector<long long> (c+1,0);
        
    }

    for(i = 0; i <= c; i++){
        for(j = 1; j <= k; j++) dp[0][j][i] = -1e18;
    }


    for(i =1; i <= n; i++){
        for(j = 0; j <= c; j++){
            for(l = 0; l <= k; l++){
                dp[i][l][j] = dp[i-1][l][j];


                if(j - stuffs[i].first >= 0){
                    dp[i][l][j] = max(dp[i][l][j], dp[i-1][l][j-stuffs[i].first] + stuffs[i].second);
                    if(l) dp[i][l][j] = max(dp[i][l][j], dp[i-1][l-1][j-stuffs[i].first]);

                }
            }
        }
    }



    vector<int> cur;


    long long ans = 0;
    for(i = n; i >= 1; i--){
        for(j = 0; j <= k; j++){
            

            for(l = n; l > i; l--) cur.push_back(stuffs[l].second);
            if(cur.size() < j) break;
            sort(cur.rbegin(), cur.rend());

            long long tot = 0;
            for(l = 0; l < j; l++) tot += cur[l];
            //cout << i << " " << j << " " <<dp[i][c][j] << " " << tot << "\n";
            ans = max(ans, dp[i][j][c] + tot);
            
            cur.clear();
        }
    }

    cout << ans << "\n";
}