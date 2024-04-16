#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        if(n < 4){
            cout << "-1\n";
            continue;
        }

        for(int i = n; i >= 1; i--){
            if(i&1) cout << i << " ";
        }

        cout << "4 2 ";

        for(int i = 6; i <= n; i++){
            if(!(i&1)) cout << i << " ";
        }

        cout << "\n";
    }
}