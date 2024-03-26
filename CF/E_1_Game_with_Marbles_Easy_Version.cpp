//each index can be chosen once at max
//in each move we either cash out or block them
//sort by difference and go from there
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 7;

int n;

long long a[MAXN][2], rebuild[MAXN][MAXN][MAXN];

long long dp[MAXN][MAXN][MAXN];

bool vis[MAXN][MAXN][MAXN];

long long solve(int i, int ca, int cb){
    if(ca < 0 || cb < 0) return -1e18;
    if(i >= n && !ca && !cb) return 0;
    if(i >= n) return -1e18;

    if(!vis[i][ca][cb]){
        vis[i][ca][cb] = 1;
        
        long long f = solve(i+1, ca-1,cb);
        long long s = solve(i+1, ca, cb-1);

        if()
       
        dp[i][ca][cb] = max(solve(i+1, ca-1,cb) + a[i][0] - 1, solve(i+1, ca, cb-1) + a[i][1] + 1);

    }

    return dp[i][ca][cb];
}



int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i][0];
        for(int i = 0; i < n; i++) cin >> a[i][1];

        memset(vis, 0, sizeof(vis));

        cout << solve(0, (int)ceil(n/2.0), n/2) << "\n";

        

       

    }
}