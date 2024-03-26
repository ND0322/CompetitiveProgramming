#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int g,b,k; cin >> g >> b >> k;

    while(k--){
        if(g >= 2*b) g--;
        else b--;
    }

    cout << min(g/2,b) << "\n";
}