#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//exchange arguement
//combine states 

const int MAXN = 2005;

int n, dp[MAXN][MAXN<<1], k1, k2;

pair<int, pair<int,int>> a[MAXN];

int main(){
    cin >> n >> k1 >> k2;

    for(int i = 1; i <= n; i++) cin >> a[i].second.first >> a[i].second.second >> a[i].first;

    sort(a+1, a+n+1);

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= k1 + k2; j++){
            dp[i][j] = dp[i+1][j];

            //buy 
            if(j > k1){
                int disc = j-k1;

                //find real cost

               

                if(a[i].second.second < disc/a[i].first) dp[i][j] = max(dp[i][j], dp[i+1][j - a[i].first * (disc/a[i].first)] + a[i].second.first);
                else{
                    int c = a[i].second.second - disc / a[i].first;
                    if(c <= k1) dp[i][j] = max(dp[i][j], dp[i+1][k1 - c] + a[i].second.first);
                }

            }
            else{
                //raw dawg

                if(a[i].second.second <= j) dp[i][j] = max(dp[i][j], dp[i+1][j-a[i].second.second] + a[i].second.first);
            }
        }
    }

    cout << dp[1][k1+k2] << "\n";



    
}