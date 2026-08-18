#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, x1,x2,k; cin >> n >> x1 >> x2 >> k;

        if(n <= 3){
            cout << "1\n";
            continue;
        }

   
        cout << k + min((x1 - x2 + n) % n, (x2 - x1 + n) % n) << "\n";
        




    }
}