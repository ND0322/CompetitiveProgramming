#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, dp[MAXN][2][2];

set<int> c[3];


string s;

int solve(int i, int a, int b){
    if(i == n) return 0;

    if(dp[i][a][b] == -1){
        if(c[0].lower_bound(i+1) != c[0].end()) dp[i][a][b] = max(dp[i][a][b], solve(*c[0].lower_bound(i+1),b,1) + 2 + (a&&b));
        if(c[1].lower_bound(i+1) != c[1].end()) dp[i][a][b] = max(dp[i][a][b], solve(*c[1].lower_bound(i+1), b, 0) + 1);
        if(c[2].lower_bound(i+1) != c[2].end()) dp[i][a][b] = max(dp[i][a][b], solve(*c[2].lower_bound(i+1), b, 0));
    }

    return dp[i][a][b];
}

int main(){
    string t; cin >> t;

    n = t.size();
    s = '_';
    s += t;

    for(int i = 1; i <= n; i++){
        if(s[i] == 'W') c[0].insert(i);
        if(s[i] == 'D') c[1].insert(i);
        if(s[i] == 'L') c[2].insert(i);
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0,0) << "\n";

}