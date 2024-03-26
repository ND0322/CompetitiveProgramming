#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int ans = 0;
        int ans1 = 0;

        for(int i = 1; i <= n; i++){
            int x,y; cin >> x >> y;

            if(x > 10) continue;

            if(y > ans){
                ans = y;
                ans1 = i;
            }
        }

        cout << ans1 << "\n";
    }
}