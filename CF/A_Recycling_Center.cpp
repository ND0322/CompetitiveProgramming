#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        int ans = 0;
        vector<int> a;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(x > k) ans++;
            else a.push_back(x);
        }

        int cnt = 0;
        long long cur = 1;

        sort(a.rbegin(), a.rend());

        for(int i : a){
            if(cur * i > k) continue;
            cur*=2;
            cnt++;
        }


        cout << ans + (int)a.size() - cnt << "\n";
    }
}