#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c,d; cin >> a >> b >> c >> d;


        c -= a;
        d -= b;

        if(max(a,b) > (min(a,b)+1) * 2  || max(c,d) > (min(c,d)+1) * 2) cout << "NO\n";
        else cout << "YES\n";
    }
}