#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x; cin >> x;

        

        if((x & (x - 1)) == 0){
            x &= -x;
            if(x == 1 || x == 2) cout << "3\n";
            else cout << x+1 << "\n";
        }
        else{
            x &= -x;
            cout << x << "\n";
        }

    
    }
}