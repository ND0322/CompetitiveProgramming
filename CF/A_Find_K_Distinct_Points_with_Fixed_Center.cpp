#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x,y,k; cin >> x >> y >> k;

        if(k & 1){
            cout << x*k << " " << y*k << "\n";
            for(int i = 1; i <= k/2; i++) cout << "0 " << i << "\n0 " << -i << "\n";
        }
        else{
            if(x == 0 && y == 0){
                cout << x*k-1 << " " << y*k-1 << "\n";
                cout << "1 1\n";
            }
            else{
                cout << x*k << " " << y*k << "\n";
                cout << "0 0\n";
            }
            for(int i = 1; i <= (k-2)/2; i++) cout << "0 " << i << "\n0 " << -i << "\n"; 
        }
        
        
    }
}