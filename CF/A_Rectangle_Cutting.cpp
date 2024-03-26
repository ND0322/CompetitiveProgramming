#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x,y; cin >> x >> y;

        if(x > y) swap(x,y);

        if(!(x&1) && !(y&1)){
            cout << "YES\n";
            continue;
        }

        if((x&1) && (y&1)){
            cout << "NO\n";
            continue;
        }

        if((x&1) && y == 2*x){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}