#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long x,y; cin >> x >> y;

   

        long long k = y/x;

        if(k != 2) cout << "YES\n";
        else cout << "NO\n";
    }
}