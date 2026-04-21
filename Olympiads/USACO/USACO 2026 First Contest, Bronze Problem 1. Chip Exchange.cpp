#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b, ca,cb, fa; cin >> a >> b >> ca >> cb >> fa;

        a += ca * (b / cb);
        b %= cb;

        if(a >= fa){
            cout << "0\n";
            continue;
        }

        int ans = max(cb - b - 1, 0LL);


        int opt1 = max(fa - a, 0LL);

        //increase a so that fa - a = b-1 (mod b)
        cout <<fa- a << "\n";
        int opt2 = cb - ((fa-a) % ca);

        a += ca;

        cout << a << "\n";
        cout << (fa-a) << "\n";
        cout << ceil((fa-a)/(long double)ca) << " " << ceil((fa-a)/(long double)ca) * cb << "\n";

        opt2 += ceil((fa-a)/(long double)ca) * cb;

        cout << opt2 << "\n";

        cout << max(ans + max(opt1, opt2), 0LL) << "\n";
    
    }
}