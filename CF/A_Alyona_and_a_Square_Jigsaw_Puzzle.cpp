#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int sm = 0;
        int ans = 1;
        int cur = 8;

        int x; cin >> x;

        for(int i = 1; i < n; i++){
            int x; cin >> x;

            sm += x;


            while(sm > cur){
                sm -= cur;
                cur += 8;
            }
            

            if(sm == cur){
                ans++;
                sm = 0;
                cur+=8;
            }

        }

        cout << ans << "\n";
    }
}