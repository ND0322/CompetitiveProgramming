#include <bits/stdc++.h>
#include <iostream>


using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        if(n&1){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(int i = 0; i < n/2; i++) cout << "AAB";
        cout << "\n";
    }
}