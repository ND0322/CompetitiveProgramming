#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,k; cin >> a >> b >> k;

        cout << min(a,k) * min(b,k) << "\n";
    }
}