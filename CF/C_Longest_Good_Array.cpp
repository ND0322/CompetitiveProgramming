#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;



    while(tt--){
        int l, r; cin >> l >> r;

        int ans = 0;
        for(int i = 1; i <= 5e4; i++){
            ans = i;
            l += i;
            if(l > r) break;
        }

        cout << ans << "\n";

        
    }
}