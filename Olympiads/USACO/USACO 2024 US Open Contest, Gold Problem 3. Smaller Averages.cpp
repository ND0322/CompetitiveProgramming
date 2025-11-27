#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;
const int MOD = 1e9+7;

#define int long long

int n, dp[MAXN][MAXN], a[MAXN], b[MAXN], psa[MAXN][MAXN];


vector<pair<double,int>> sec[MAXN];


int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= n; j++) cin >> b[j];

    dp[n+1][n+1] = 1;

    //precomp the things for k transition
    for(int j = 1; j <= n; j++){
        long long sm = 0;
        for(int k = j; k <= n; k++){
            sm += b[k];

            sec[j].push_back({sm / (double)(k-j+1), k+1});
        }

        sort(sec[j].begin(), sec[j].end());
    }

    for(int i = n; i >= 1; i--){

        //consider next for i and build psum

        vector<pair<double,int>> nxt = {{0,0}};

        long long sm = 0;

        for(int k = i; k <= n; k++){
            sm += a[k];
            nxt.push_back({sm / (double)(k-i+1), k+1});
        }

        sort(nxt.begin(), nxt.end());

        //all positions of second row
        for(int j = 1; j <= n+1; j++){
            for(int k = 1; k < nxt.size(); k++) psa[k][j] = (psa[k-1][j] + dp[nxt[k].second][j]) % MOD;
        }

     
        for(int j = n; j >= 1; j--){
            sm = 0;

            int r = 0;

            for(auto k : sec[j]){

                while(r < nxt.size() && nxt[r].first <= k.first) r++;

                dp[i][j] = (dp[i][j] + psa[r-1][k.second]) % MOD;
            }


    

        }
    }

    cout << dp[1][1] << "\n";

}