#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//put min first then max of array at 2

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int mx = 0;
        int mn = 1e9;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            mx = max(x, mx);
            mn = min(x, mn);
        }

        cout << (n-1) * (mx-mn) << "\n";
    }
}