#include <bits/stdc++.h>
#include <iostream>

using namespace std;



/*
length must be greater than minimum element 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int mn = 1e9;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            mn = min(mn, x);
        }

        if(n > mn) cout << n << "\n";
        else cout << "0\n";
    }
}