#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int ans = 1e9; //ik max is way less

        for(int i = 0; i < n; i++){
            int x,y; cin >> x >> y;

            if(x <= ans){
                ans = min(ans,x + (y-1)/2);
            }
        }

        cout << ans << "\n";
    }
}