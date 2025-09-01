#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c; cin >> a >> b >> c;

        if((a&1) == (b&1) && (b&1) == (c&1)){
            cout << "YES\n";
            continue;
        }

        if(c > b && (c&1) == (a&1)){
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}