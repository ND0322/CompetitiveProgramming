#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;


const int MAXN = 5005;

int n;

long long dp[MAXN];

map<int,int> mp;
int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x,y; cin >> x >> y;

        x = abs(x);
        y = abs(y);

        mp[x] = max(mp[x], y);
    }

    int n = mp.size();

    vector<pair<long long,long long>> a = {{0,0}};

    for(auto i : mp) a.push_back({i.first, i.second});

    for(int i = n; i >= 1; i--){

        dp[i] = 1e18;
        long long mx = 0;
        for(int j = i; j <= n; j++){
            mx = max(mx, a[j].second);
            dp[i] = min(dp[i], dp[j+1] + mx * 4 * a[j].first);
        }
    }
    

    cout << dp[1] << "\n";


}