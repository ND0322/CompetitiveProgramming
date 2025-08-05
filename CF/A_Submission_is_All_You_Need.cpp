#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int ans = 0;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            ans += max(x, 1);
        }

        cout << ans << "\n";
    }
}