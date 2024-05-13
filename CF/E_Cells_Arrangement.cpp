#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        for(int i = 1; i <= n-2; i++) cout << i << " " << i << "\n";
        cout << n << " " << n << "\n";
        cout << n-1 << " " << n << "\n";
    }
}