#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//can solve offline too

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k, q; cin >> n >> k >> q;

        vector<int> a(k+2);
        vector<int> b(k+2);

        for(int i = 1; i <= k; i++) cin >> a[i];
        for(int i = 1; i <= k; i++) cin >> b[i];

        while(q--){
            int d; cin >> d;

            if(d == n){
                cout << b[k] << " ";
                continue;
            }
            int i = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;

            cout << (long long)(b[i] + (d - a[i]) * ((b[i+1] - b[i]) / (long double)(a[i+1] - a[i]))) << " ";
        }

        cout << "\n";


    }
}