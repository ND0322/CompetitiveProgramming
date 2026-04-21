#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        int sm = 0;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            sm += x;
        }

        if(sm & 1){
            cout << "YES\n";
            continue;
        }

        if(!((k * n) & 1)){
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";


    }
}