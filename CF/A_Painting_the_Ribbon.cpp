#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m,k; cin >> n >> m >> k;

        if(m == 1){
            cout << "NO\n";
            continue;
        }

        if(k == n){
            cout << "NO\n";
            continue;
        }

        if(n-ceil(n/(double)m) > k) cout << "YES\n";
        else cout << "NO\n";
        
    }
}