#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        if(n == 1){
            cout << k << "\n";
            continue;
        }

        cout << (1<<((int)log2(k+1)))-1 << " ";
        cout << k-((1<<((int)log2(k+1)))-1) << " ";
        for(int i = 1; i <= n-2; i++) cout << "0 ";
        cout << "\n";

    }
}