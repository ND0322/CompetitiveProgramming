#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        for(int i = n-k; i <= n; i++) cout << i << " ";

        for(int i = n-k-1; i >= 1; i--) cout << i << " ";
        cout << "\n";
    }
}