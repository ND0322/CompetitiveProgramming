#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;

const int MAXN = 1e4+5;

int n, k, a[MAXN];


vector<double> dp[4];


//runtimes probably nk


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[2].push_back(0);
    dp[1].push_back(a[n]);
    if(min(a[n], a[n-1])) dp[0].push_back(a[n] + a[n-1] - min(a[n], a[n-1])/2.0);
    dp[0].push_back(a[n] + a[n-1]);
    for(int i = n-2; i >= 1; i--){

        int l = 0;
        int b = 0;
        int c = 0;

        int cnt = 0;

        while(l < dp[0].size() || b < dp[1].size() || c < dp[2].size()){
            double aa = (l < dp[0].size() ? dp[0][l] + a[i] : 1e9);
            double bb = (b < dp[1].size() ? dp[1][b] + a[i] + a[i+1] - min(a[i], a[i+1])/2.0: 1e9);
            double cc = (c < dp[2].size() ? dp[2][c] + a[i] + a[i+1] + a[i+2] - min({a[i], a[i+1], a[i+2]}): 1e9);

            dp[3].push_back(min({aa,bb,cc}));
            cnt++;

            if(cnt == k) break;

            if(min({aa,bb,cc}) == aa) l++;
            if(min({aa,bb,cc}) == bb) b++;
            if(min({aa,bb,cc}) == cc) c++;
        }
       
  
        dp[2] = dp[1];
        dp[1] = dp[0];
        dp[0] = dp[3];
        dp[3].clear();
        
    }

    if((int)dp[0].size() != k){
        cout << "-1\n";
        return 0;
    }

    sort(dp[0].begin(), dp[0].end());

    cout << setprecision(1) << fixed << dp[0][k-1] << "\n";


}