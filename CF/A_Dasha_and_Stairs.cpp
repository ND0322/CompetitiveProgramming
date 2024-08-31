#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int x,y; cin >> x >> y;

    if(x == 0 && y == 0){
        cout << "NO\n";
        return 0;
    }
    if(abs(x-y) > 1) cout << "NO\n";
    else cout << "YES\n";
}