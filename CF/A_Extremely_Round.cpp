#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        //9 * log x
        //plus overfill

        int x; cin >> x;

        int ans = 0;

        while(x > 9){
            x /= 10;
            ans += 9;
        }

        ans += x;
        cout << ans << "\n";
    }
}