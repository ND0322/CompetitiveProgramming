#include <bits/stdc++.h>    
#include <iostream>

using namespace std;

#define int long long

/*
h <= (n-1)(a-b) + a
h >= (n-2)(a-b) + a

*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int q; cin >> q;

        int l = 1;
        int r = 1e18;

        while(q--){
            int t; cin >> t;

            if(t == 1){
                int a,b,n; cin >> a >> b>> n;

                int ql = (n-1) * (a-b) + a;
                int qr = (n-2) * (a-b) + a + 1;

                if(n == 1){
                    ql = 1;
                    qr = a;
                }

                if(ql > r || qr < l){
                    cout << "0 ";
                    continue;
                }

                l = max(ql, l);
                r = min(qr, r);

                cout << "1 ";
            }
            else{
                int a,b; cin >> a >> b;
                int ans1 = max(1LL,(l - b - 1) / (a - b) + 1) , ans2 = max(1LL,(r - b - 1) / (a - b) + 1);
                if(ans1 == ans2) cout << ans1 << " ";
                else cout << "-1 ";

            }
        }

        cout << "\n";
    }
}