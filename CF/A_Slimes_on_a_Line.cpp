#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int mx = 0;
        int mn = 1e9;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            mx = max(mx, x);
            mn = min(mn, x);
        }

        cout << (int)ceil((mx - mn) / 2.0) << "\n";
    }
}