#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 20;

int n, m, a[MAXN], b[MAXN][MAXN], k, dp[1<<18][MAXN];

//mask, last eaten, num eaten = popcount

int solve(int mask, int last, int d){
    if(d == m) return dp[mask][last] = 0;

    

    if(dp[mask][last] == -1){
        dp[mask][last] = 0;
        for(int i = 0; i < n; i++){
            if(!(mask & (1<<i))){
                
                dp[mask][last] = max(dp[mask][last], solve(mask ^ (1<<i), i, d+1) + a[i] + b[last][i]);
               
            }
        }
    }

    return dp[mask][last];
}

int32_t main(){
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) cin >> a[i];

    

    for(int i = 0; i < k; i++){
        int x,y,c; cin >> x >> y >> c;
        x--;
        y--;
        b[x][y] = c;
    }

    
    
    //4 2 1
    //4 + 2 + 1 + 5
    memset(dp, -1, sizeof(dp));

    cout << solve(0,n,0) << "\n";
}