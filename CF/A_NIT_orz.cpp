#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        int ans = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;
            ans = max(ans, x | k);
        }
        
        cout << ans << "\n";
    }
}