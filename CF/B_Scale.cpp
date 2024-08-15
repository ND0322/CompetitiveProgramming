#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        vector<string> a(n);

        for(int i = 0; i <n ; i++) cin >> a[i];

        for(int i = 0; i < n; i+=k){
            for(int j = 0; j < n; j+=k) cout << a[i][j];
            cout << "\n";
        }
    }
}