#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int ans = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(!(i & 1)) ans = max(ans, x);
        }

        cout << ans << "\n";
    }
}