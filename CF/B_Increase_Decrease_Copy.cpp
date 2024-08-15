#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<long long> a(n+1), b(n+2);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n+1; i++) cin >> b[i];

        long long ans = 0;

        for(int i = 1; i <= n; i++) ans += abs(b[i] - a[i]);

        long long best = 1e9;

        //check the ranges

        for(int i = 1; i <= n; i++){
            int l = min(a[i], b[i]);
            int r = max(a[i], b[i]);

            if(b[n+1] >= l && b[n+1] <= r) best = 0;
            else best =min({best, abs(b[n+1] - l), abs(b[n+1] - r)});
        }

        cout << ans + best + 1 << "\n";
    }
}