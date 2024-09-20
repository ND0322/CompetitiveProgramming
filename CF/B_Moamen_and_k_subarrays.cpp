#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<pair<int,int>> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        int cnt = 1;

        for(int i = 0; i < n-1; i++){
            if(a[i].second != a[i+1].second-1) cnt++;
        }

        cout << (cnt <= k ? "YES\n" : "NO\n");
    }
}