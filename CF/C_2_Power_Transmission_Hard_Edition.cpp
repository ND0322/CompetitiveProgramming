#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1005;



int n, x[MAXN], y[MAXN];
set<pair<long double, long double>> s;

map<long double, int> slopes;
int32_t main(){
    
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            long double m = (y[j] - y[i]) / (long double)(x[j] - x[i]);

            if(x[j] == x[i]) s.insert({1e18, x[i]});
            else s.insert({m, y[i] - m * x[i]});
        }
    }

    for(auto [m,b] : s) slopes[m]++;
    

    long long ans = (s.size() * (s.size()-1))/2;

    for(auto [a,b] : slopes) ans -= (b * (b-1))/2;
    cout << ans << "\n";




}