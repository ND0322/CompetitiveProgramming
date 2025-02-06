#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, a, b; cin >> n >> a >> b;

        cout << (max(a,b) - min(a,b) & 1 ? "NO\n" : "YES\n");
    }
}