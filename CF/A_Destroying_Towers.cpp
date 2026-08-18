#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int pmn = 1e9;

        int ans = 0;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            pmn = min(pmn, x);
            ans += pmn;
        }

        cout << ans << "\n";
    }
}