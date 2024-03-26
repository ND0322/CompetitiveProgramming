#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        string c; cin >> c;

        int ans = n;

        for(int i = 0; i < n-1; i++){
            string t; cin >> t;

            if(c != t) ans--;
        }

        cout << ans << "\n";
    }
}