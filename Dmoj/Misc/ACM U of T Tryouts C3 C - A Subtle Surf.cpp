#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e5+5;

#define int long long

int n, a[MAXN], k, p;

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k >> p;

        set<int> s;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }

        int cur = a[1];
        int cnt = 0;

        while(1){
            auto it = s.lower_bound(cur + k + 1);

            it--;

            if(*it <= cur) break;
            cnt++;
            cur = *it;
        }

        cout << cur << " " << cnt*p << "\n";


    }
}