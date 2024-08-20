#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;
    
    while(tt--){
        int n,k; cin >> n >> k;

        if(n == 1 && k == 1){
            cout << "0\n";
            continue;
        }

        if(k == 2){
            cout << n-1 << "\n";
            for(int i = n; i > k; i--) cout << i << " ";
            cout << "1\n";
            continue;
        }

        cout << n-k + k/2 << "\n";
        for(int i = n; i > k; i--) cout << i << " ";
        for (int i = (k + 1) / 2; i < k; ++i) cout << i << " ";

        cout << "\n";

    }
}