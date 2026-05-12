#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        int ans = 1e9;
        for(int i = 1; i <= n; i++){
            int cnt = 0;

            for(int j = i+1; j <= n; j++) cnt += (a[j] > a[i]);

            ans = min(ans, i-1 + cnt);
        }

        cout << ans << "\n";
    }
}