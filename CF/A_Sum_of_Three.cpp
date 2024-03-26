#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        if(n % 3){
            if(n < 7) cout << "NO\n";
            else cout << "YES\n1 2 " << n-3 << "\n";
            
        }
        else{
            if(n < 10) cout << "NO\n";
            else cout << "YES\n1 4 " << n-5 << "\n";
        }
    }
}