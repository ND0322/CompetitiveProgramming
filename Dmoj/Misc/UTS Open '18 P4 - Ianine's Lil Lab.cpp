#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], b[MAXN];
map<int,vector<int>> mp;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];

        mp[a[i] + b[i]].push_back(i);
    }

    long long ans = 0;


    for(auto [z,v] : mp){
        vector<pair<int,int>> tmp;

        for(int i : v) tmp.push_back({a[i], b[i]});

        long long suf = 0;
        sort(tmp.rbegin(), tmp.rend());

        for(auto [x,y] : tmp) suf += y;
        long long pref = 0;

        for(auto [x,y] : tmp){
            pref += x;
            suf -= y;
            ans = max(ans, min(pref, suf));
        }
    }

    cout << ans << "\n";
}