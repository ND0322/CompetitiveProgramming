#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long
/*
either thing in slot 1 or the last thing in slot 2 will be unused 

find a subsequence

fix the right end point of the 1s
*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        int sm = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sm -= a[i];
        }

        sm += a[n];
        sm += a[1];

        int ans = -1e9;
        for(int i = 1; i < n; i++){
            ans = max(ans, sm + max(a[i], -a[n]));
            sm += a[i+1];

            if(i != 1) sm += abs(a[i]);
            else sm += a[i];
        }

        cout << ans << "\n";
    }
}