#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,c[MAXN], host[MAXN],t[MAXN];

long long dp[MAXN][2];


int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 1; i < n; i++){
        cin >> host[i] >> t[i];
    }

    for(int i = 0; i < n; i++) dp[i][1] = c[i];

    for(int i = n-1; i > 0; i--){
        if(!t[i]){
            dp[host[i]][0] += max(dp[i][0], dp[i][1]);
            
            //take host cant take this dude
            dp[host[i]][1] += dp[i][0];
        }
        long long tmp = dp[host[i]][0];
        if(t[i] == 1){
            
            dp[host[i]][0] += dp[i][0];
            dp[host[i]][1] = max({dp[host[i]][1] + dp[i][1], dp[host[i]][1] + dp[i][0], tmp + dp[i][1]});
           
        }
        if(t[i] == 2){
            dp[host[i]][0] += dp[i][0];
            dp[host[i]][1] = max(dp[host[i]][1] + dp[i][0], tmp + dp[i][1]);
        }
    }

    cout << max(dp[0][0], dp[0][1]) << "\n";
}