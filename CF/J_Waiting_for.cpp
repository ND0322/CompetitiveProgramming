#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int q; cin >> q;

    int sm = 0;

    while(q--){
        char c; cin >> c;

        if(c == 'P'){
            int x; cin >> x;
            sm += x;
        }

        if(c == 'B'){
            int x; cin >> x;

            if(x > sm) cout << "YES\n";
            else cout << "NO\n";
            sm -= min(sm, x);
        }
    }
}