#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

#define int long long

int n, q, k, diff[MAXN], a[MAXN]; 

int32_t main(){
    cin >> n >> q >> k;

    set<int> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }

    set<int, greater<int>> t;

    for(int i = 0; i < n; i++){
        if(s.find(i) == s.end()) t.insert(i);
    }

    while(q--){
        int l,r; cin >> l >> r;

        l++;
        r++;

        diff[l]++;
        diff[r+1]--;
    }

    vector<pair<int,int>> inds;

    for(int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
        inds.push_back({diff[i], i});
    }

    sort(inds.rbegin(), inds.rend());


    int ans = 0;

    for (auto [cnt, pos] : inds){
        if(a[pos] != -1) ans += cnt * a[pos];
        else{
            ans += *t.begin() * cnt;
            t.erase(t.begin());
        }
    }

    cout << ans << "\n";

}