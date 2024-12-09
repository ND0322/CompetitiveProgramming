#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, r; cin >> n >> r;

        int sm = 0;
        int ans = 0;
        int tot = 0;
        
        for(int i = 0; i < n; i++){
            int x; cin >> x;

            tot += x;

            r -= x/2;
            ans += (x/2) * 2;
            sm += x&1;
        }


        r -= ceil(sm/2.0);

        if(sm & 1) ans++;

        int cnt = sm/2;

        cout << min(r, cnt) * 2 + ans << "\n";
    }
}