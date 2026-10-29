#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

//go right to left 
//raise this until it is 1
//-1 for all in the prefix

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        int sm = 0;

        int ans = 0;
        for(int i = n ; i >= 1; i--){
            a[i] += sm;

            if(a[i] > 0) continue;

            int cnt = 1-a[i];

            ans += cnt;
            sm += -cnt;
        }

        cout << ans+1 << "\n";


    }
}