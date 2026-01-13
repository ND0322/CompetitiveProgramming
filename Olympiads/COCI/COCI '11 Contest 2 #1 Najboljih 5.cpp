#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    vector<pair<int,int>> a;

    for(int i = 1; i <= 8; i++){
        int x; cin >> x;

        a.push_back({x, i});
    }

    sort(a.rbegin(), a.rend());

    int sm = 0;

    vector<int> ans;
    for(int i = 0; i < 5; i++){
        sm += a[i].first;
        ans.push_back(a[i].second);
    }

    cout << sm << "\n";
    sort(ans.begin(), ans.end());
    for(int i : ans) cout << i << " ";
    cout << "\n";
}