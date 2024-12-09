#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x,y,k; cin >> x >> y >> k;

        x = min(x,y), y = min(x,y);

        cout << "0 0 " << x << " " << y << "\n";
        cout << x << " 0 0 " << y << "\n"; 
    }
}