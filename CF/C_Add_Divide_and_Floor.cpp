#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int big = 0;
        int small = 1e9;

        int n; cin >> n;

        for(int i = 0; i < n; i++){
            int x; cin >> x;
            big = max(big, x);
            small = min(small,x);
        }

        int tmp = big;
        long long ans = 0;

        while(tmp != small){
            tmp = (tmp+small)>>1;
            ans++;
        }

        cout << ans << "\n";

        bool yes = ans;
        if(ans <= n){
            while(ans--) cout << small << " ";
        }

        if(yes) cout << "\n";
    }
}