#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        if(!(n&1)){
            cout << "YES\n";
            for(int i = 0; i < n/2; i++){
                cout << "1 -1 ";
            }
            
            cout << "\n";
            continue;
        }

        if(n == 3){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        //n/2-1 -n/2 n/2+1
        for(int i = 0; i < n/2; i++){
            cout << n/2-1 << " " << -n/2 << " ";
        }

        cout << n/2-1 << "\n";
    }
}