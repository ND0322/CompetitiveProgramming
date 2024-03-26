#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        cout << "2\n";

        for(int i = 1; i <= n; i++){
            if(i&1){
                for(int j = i; j <= n; j<<=1) cout << j << " ";
            }
        }

        cout << "\n";
    }
}