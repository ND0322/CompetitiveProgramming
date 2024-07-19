#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b; cin >> a >> b;

        if(a < b){
            cout << "No\n";
            continue;
        }

        if((a&1) == (b&1)){
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
}