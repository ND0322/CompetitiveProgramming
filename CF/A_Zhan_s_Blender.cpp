#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//max ceil(n/y), n / x

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int x, y; cin >> x >> y;

        cout << max(ceil(n/(double)x), ceil(n/ (double)y)) << "\n";
    }
}