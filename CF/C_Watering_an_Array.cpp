#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k,d; cin >> n >> k >> d;

        vector<int> a(n);
        vector<int> b(k);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < k; i++) cin >> b[i];


        long long ans = 0;
        for(int i = 1; i <= min(2*n+1, d); i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(a[j] == j+1) cnt++;
            }

            //if(i == 1) cout << cnt << "\n";
            //if(cnt + (d-i)/2 == 2) cout << cnt << " " << i << "\n";
            ans = max(ans, cnt + (d-i)/2);

            for(int j = 0; j < b[(i-1) % k]; j++) a[j]++;
        }

        cout << ans << "\n";

    }
}

/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/