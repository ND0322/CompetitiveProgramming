#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long b,c,d; cin >> b >> c >> d;

        long long a = b ^ d;

        if((a|b) - (a & c) != d){
            cout << "-1\n";
            continue;
        }

        cout << a << "\n";
    }
}