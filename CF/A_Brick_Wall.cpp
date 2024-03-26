#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        if(m % 2 == 0){
            cout << n*m/2 << "\n";
            continue;
        }

        cout << ((m-1) * n)/2 << "\n";
    }
}