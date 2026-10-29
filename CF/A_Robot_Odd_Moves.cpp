#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x,y; cin >> x >> y;

        if(y > x+1){
            cout << "-1\n";
            continue;
        }


        if(y == x+1) cout << y << "\n";
        else if((x-y) & 1) cout << x+1 << "\n";
        else cout << x << "\n";
    }
}