#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")


using namespace std;

const int MAXN = 1e6+5;

int n,m, a[MAXN], b[MAXN];



map<int,int,greater<int>> c;
map<int,int> mp;
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        c[x]++;
    }

    for(int i = 1; i <= n; i++){
        if(mp.find(a[i] - b[i]) != mp.end()) mp[a[i] - b[i]] = min(mp[a[i] - b[i]], a[i]);
        else mp[a[i] - b[i]] = a[i];
    }

    long long ans = 0;

    for(auto i : mp){
        int diff = i.first;
        int ai = i.second;

        vector<int> del;

        for(auto j : c){
            int x = j.first;
            int cnt = j.second;

            if(x < ai) break;

            long long sp = (x - ai + diff) / diff;

            ans += 2*sp*cnt;
            c[x - sp * diff] += cnt;
            del.push_back(x);
        }

        for(int i : del) c.erase(i);

    }

    cout << ans << "\n";

   


    

}