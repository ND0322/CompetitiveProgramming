#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        long long prod = 1;

        for(int i = 0; i < n; i++){
            int x; cin >> x;
            prod*=x;
        }

        if(2023%prod != 0){
            cout << "NO\n";
            continue;
        }

        int tar = 2023/prod;

        cout << "YES\n";
        cout << tar << " ";

        for(int i = 0; i < k-1; i++) cout << "1 ";
        cout << "\n";
    }
}