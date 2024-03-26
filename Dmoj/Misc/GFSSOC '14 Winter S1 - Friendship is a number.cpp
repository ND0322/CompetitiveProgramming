#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

vector<pair<int,int>> p;

int32_t main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int t; cin >> t;

        int cur = 1;
        for(int j = 0; j < t; j++){
            int x; cin >> x;
            cur *= x;
        }

        p.push_back({cur,i+1});
    }

    sort(p.rbegin(),p.rend());

    cout << p[0].second << "\n" << p[1].second << "\n" << p[2].second << "\n";
}