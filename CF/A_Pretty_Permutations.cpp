#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        if(n&1){
            cout << "3 1 2 ";
            for(int i = 4; i <= n; i+=2) cout << i+1 << " " << i << " ";
            cout << "\n";
        
        }
        else{
            for(int i = 1; i <= n; i+=2){
                cout << i+1 << " " << i << " ";
            }

            cout << "\n";
        }

    }
}