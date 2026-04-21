#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e3+5;
int n, a[MAXN], b[MAXN], k, dp[MAXN], su, sd;

int32_t main(){
    cin >> n >> su >> sd >> k;

    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    map<int,int> mp;

    vector<pair<int,pair<int,int>>> c = {{0,{0,0}}};

    for(int i = 1; i <= n; i++){
        if(a[i] != a[i-1]){
            for(auto j : mp) c.push_back({a[i-1], {j.first, j.second}});
            mp.clear();
        }

        mp[b[i]]++;
        if(k && b[i] >= k) mp[b[i] - k]++;
    }

    for(auto j : mp)c.push_back({a[n], {j.first, j.second}});

    sort(c.begin(), c.end());

    n = c.size()-1;

    for(int i = n; i >= 0; i--){

        for(int j = i+1;j <= n; j++){
            //h2 - h1 / (a2 - a1) <= d
            
            if(c[j].second.first >= c[i].second.first && (c[j].second.first - c[i].second.first) <= su * (c[j].first - c[i].first))
                dp[i] = max(dp[i], dp[j]);

            if(c[j].second.first < c[i].second.first && (c[i].second.first - c[j].second.first) <= sd * (c[j].first - c[i].first))
                dp[i] = max(dp[i], dp[j]);

        }
        dp[i] += c[i].second.second;
    }

    cout << dp[0] << "\n";



}