#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 1e4+5;


int n,q, dp[2005][3005], a[2005];

map<pair<int,int>, int> mp;

int f(int c, int p){
    //cout << c << " " << p << "\n";
    if(c < 0) return 1e9;
    if(c <= 3000) return dp[p][c];
    if(mp.find({c,p}) != mp.end()) return mp[{c,p}];
    int mn = 1e9;
    for(int i = 1; i <= p; i++) mn = min(mn, f(c-a[i], p)+1);
    mp[{c,p}] = mn;
    return mn;
}
int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 3000; j++){
            dp[i][j] = dp[i-1][j];
            if(j - a[i] >= 0) dp[i][j] = min(dp[i][j], dp[i][j-a[i]]+1);
        }
    }

    

    while(q--){
        int c, p; cin >> c >> p;
        int res = f(c, p);
        cout << (res == 1061109567 ? -1 : res) << "\n";
    }

}