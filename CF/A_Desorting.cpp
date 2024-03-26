#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve(){
    int n; cin >> n;

        int small = 1e9;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < n-1; i++){
            if(a[i+1] - a[i] < 0){
                cout << "0\n";
                return;
            } 

            small = min(small,a[i+1] - a[i]);
        }

        cout << small/2 + 1 << "\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
    }
}