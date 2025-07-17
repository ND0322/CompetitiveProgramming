#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c; cin >> a >> b >> c;

        if(a >= min(b,c) && a <= max(b,c)) cout << "NO\n";
        else cout << "YES\n";
    }
}