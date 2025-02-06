#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int l,r,g; cin >> l >> r >> g;

        int lo = ceil(l/(double)g);
        int hi = r/g;

        if(hi - lo < 1) cout << "-1 -1\n";
        else cout << g * lo << " " << g *hi << "\n";
    }
}