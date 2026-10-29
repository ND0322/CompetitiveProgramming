#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 3e5+5;

int n, k, a[MAXN];
map<int,int> dp[MAXN];

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}


int solve(int i, int x){
    if(i == n+1) return 0;

    if(dp[i].find(x) != dp[i].end()) return dp[i][x];

    //take or dont take

    dp[i][x] = solve(i+1,x);


    if(gcd(a[i], x) != 1) dp[i][x] = max(dp[i][x], solve(i+1, gcd(a[i], x)) + a[i]);
    return dp[i][x];
}
int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        for(int i = 1; i <= n; i++) dp[i].clear();
        for(int i = 1; i <= n; i++) cin >> a[i];

        cout << solve(1, k) << "\n";

       
    }
}