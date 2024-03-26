#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        if(n == 1){
            cout << "1\n";
            continue;
        }

        if(n&1){
            cout << "-1\n";
            continue;
        }

        for(int i = 2; i <= n; i += 2) cout << i << " " << i-1 << " ";
        cout << "\n";
    }
}