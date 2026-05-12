#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        
        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        int cnt = 0;
        for(int i = n-1; i >= 1; i--){
            if(a[i+1] >= 0) a[i] += a[i+1];

            cnt += (a[i] > 0);
        }


        cout << cnt + (a[n] > 0) << "\n";
    }
}