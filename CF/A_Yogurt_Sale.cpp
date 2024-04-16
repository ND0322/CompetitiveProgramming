#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, a,b; cin >> n >> a >> b;

        if(2*a < b){
            cout << n*a << "\n";
            continue;
        }

        cout << (n/2) * b + (n&1) * a << "\n";
    }
}