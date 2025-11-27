#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e4+5;
const int MOD =1e9+7;

int n, m,c, dp[105][MAXN];

pair<int,int> a[MAXN];
map<int,int> mp;

/*
for some hi and hj

if hi < hj
then ai < aj
*/


int fastpow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        
        b >>=1;
        a = (a * a) % MOD;
    }
    return res;
}

int32_t main(){
    cin >> n >> m >> c;


    for(int i = 1; i <= m; i++){
        cin >> a[i].second >> a[i].first;
        if(mp.find(a[i].first) == mp.end()) mp[a[i].first] = a[i].second;
        else mp[a[i].first] = min(mp[a[i].first], a[i].second);
    }

    sort(a+1, a+m+1);

    set<int> s;
    bool flag = 1;
    for(int i = 1; i < m; i++){
        flag &= (a[i].second <= a[i+1].second);
        s.insert(a[i].first);
    }  

    s.insert(a[m].first);



    if(!flag){
        cout << "0\n";
        return 0;
    }

    vector<int> b;

    b.push_back(0);

    mp[0] = 0;
    for(int i : s) b.push_back(i);

    int ans = fastpow(c, n - *b.rbegin());


    n = b.size()-1;

    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        int sz = b[i] - mp[b[i]] - 1;
        int ps = 0;
        for(int j = 2; j <= c; j++){
            
           

            //a[i] = j
            //everything msut from 1 to j-1
            dp[i][j] = (dp[i-1][j-1] * fastpow(j-1, (b[i] - b[i-1])-1)) % MOD;
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;

            dp[i][j] = (dp[i][j] + ((ps * ((fastpow(j-1, mp[b[i]] - b[i-1] ) - fastpow(j-2, mp[b[i]] - b[i-1]) + MOD) % MOD)) % MOD * fastpow(j-1, sz)) % MOD) % MOD;
            ps = (ps + dp[i-1][j-1]) % MOD;
        }
    }

    long long sm = 0;

    for(int i = 1; i <= c; i++) sm = (sm + dp[n][i]) % MOD;
    cout << (sm * ans) % MOD << "\n";








}