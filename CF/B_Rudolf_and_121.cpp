#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve(){
    int n; cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n-2; i++){
        if(a[i] < 0){
            cout << "NO\n";
            return;
        }

        a[i+1] -= 2*a[i];
        a[i+2] -= a[i];
        a[i] = 0;
    }

    for(int i : a){
        if(i){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--) solve();
    
}