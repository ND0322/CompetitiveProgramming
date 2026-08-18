#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int k, n, m;

vector<int> b;

set<int> d;

int dp[20][3], pw[20];

int solve(int i, int st, int j){
    if(i == -1) return 0;

    if(dp[i][st] != -1) return dp[i][st];

    dp[i][st] = 1e18;
    
    if(j){
        int x = 0;
        if(st == 0 || (st == 1 && x < b[i])) dp[i][st] = min(dp[i][st], solve(i-1, 0, j-1) + (b[i] - x) * pw[i]);
        if(st == 2 || (st == 1 && x > b[i])) dp[i][st] = min(dp[i][st], solve(i-1, 2, j-1) + (x - b[i]) * pw[i]);
        if(st == 1 && x == b[i]) dp[i][st] = min(dp[i][st], solve(i-1, 1, j-1));
        return dp[i][st];
    }
    for(int x : d){
        if(st == 0 || (st == 1 && x < b[i])) dp[i][st] = min(dp[i][st], solve(i-1, 0, j) + (b[i] - x) * pw[i]);
        if(st == 2 || (st == 1 && x > b[i])) dp[i][st] = min(dp[i][st], solve(i-1, 2, j) + (x - b[i]) * pw[i]);
        if(st == 1 && x == b[i]) dp[i][st] = min(dp[i][st], solve(i-1, 1, j));
    }

    return dp[i][st];
}


int32_t main(){
    int tt; cin >> tt;

    pw[0] = 1;
    for(int i = 1; i <= 17; i++) pw[i] = pw[i-1] * 10;

    while(tt--){
        int k, n; cin >> k >> n;

        b.clear();

        d.clear();


        for(int i = 0; i < n; i++){
            int x; cin >> x;

            d.insert(x);
        }

        if(k == 0){
            cout << *d.begin() << "\n";
            continue;
        }

        int m = 0;
        int tmp = k;
        while(tmp > 0){
            b.push_back(tmp % 10);
            tmp /= 10;
            m++;
        }
        
       

        long long ans = 1e18;

        long long cur = 0;

        for(int i = 0; i < m; i++){
            memset(dp, -1, sizeof(dp));
            ans = min(ans, solve(m-1, 1, i));
        }

        b.push_back(0);
        memset(dp, -1, sizeof(dp));
        ans = min(ans, solve(m, 1, 0));
        cout << ans << "\n";


        

        

       


    }
}