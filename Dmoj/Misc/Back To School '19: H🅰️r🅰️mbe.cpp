#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    vector<pair<int,string>> a;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        a.push_back({s.size(), s});
    }

    sort(a.begin(), a.end());

    string t; cin >> t;

    string ans;
    for(int i = 0; i < n; i++){
        if(a[i].first <= t.size()) ans = a[i].second;
    }

    cout << ans << "\n";
}