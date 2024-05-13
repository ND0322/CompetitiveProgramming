#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c; cin >> a >> b >> c;

        //split a
        if(b == c && !(a&1)){
            cout << "YES\n";
            continue;
        }

        if(a-b == c){
            cout << "YES\n";
            continue;
        }

        if(a == c && !(b&1)){
            cout << "YES\n";
            continue;
        }

        if(b-a == c){
            cout << "YES\n";
            continue;
        }

        if(b == a && !(c&1)){
            cout << "YES\n";
            continue;
        }

        if(c-b == a){
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}