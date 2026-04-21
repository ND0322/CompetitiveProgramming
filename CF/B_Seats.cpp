#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;

        int sz = 0;

        int ans = 0;
        for(int i = 1; i <= n; i++){
            char c; cin >> c;

            if(c == '1'){
                ans++;
                ans += sz / 3;
                sz = 0;
                continue;
            }
            else sz++;
        }

        ans += sz / 3;

        cout << ans << "\n";

    }
}

/*

*/