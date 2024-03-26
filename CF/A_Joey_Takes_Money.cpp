#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main(){

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        ll p = 1;

        for(int i =0; i < n; i++){
            int x; cin >> x;
            p *= x;
        }

        cout << (p+n-1) * 2022 << "\n";
    }
    
}