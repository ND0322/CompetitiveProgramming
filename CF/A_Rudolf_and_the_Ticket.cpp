#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m, k; cin >> n >> m >> k;

        int ans = 0 ;

        vector<int> a(n), b(m);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) ans += (a[i] + b[j] <= k);
        }

        cout << ans << "\n";
    }
}