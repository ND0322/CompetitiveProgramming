#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//max ceil(n/y), n / x

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int x, y; cin >> x >> y;

        cout << max((int)ceil(n/(double)x), (int)ceil(n/ (double)y)) << "\n";
    }
}