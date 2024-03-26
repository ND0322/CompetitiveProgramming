#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int main(){
    int tt; cin >> tt;

    while(tt--){
        int b,c,h; cin >> b >> c >> h;

        cout << min(b-1,c+h)*2+1 << "\n";
    }
}