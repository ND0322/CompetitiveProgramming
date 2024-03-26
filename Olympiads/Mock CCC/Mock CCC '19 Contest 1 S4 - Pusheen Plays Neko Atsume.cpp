#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e7+5;

//1e7 operations for dp and 1e7 total for queries

int a,b,c,d,q,dp[MAXN];

int solve(int x){
    if(x < 1e7) return dp[x];

    return solve(x/a-b) + solve(x/c-d);
}

int solve2(int x){
    if(x <= 0) return 1;

    if(dp[x] == -1) dp[x] = solve2(x/a-b) + solve2(x/c-d);
    return dp[x];
}

int main(){
    cin >> a >> b >> c >> d >> q;

    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < MAXN; i++) solve2(i);

    while(q--){
        int x; cin >> x;

        cout << solve(x) << "\n";   
    }





    
}