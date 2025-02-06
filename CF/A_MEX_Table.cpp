#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x,y; cin >> x >> y;

        cout << max(x,y)+1 << "\n";
    }
}