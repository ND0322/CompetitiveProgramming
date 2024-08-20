#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        if(n > 2){
            cout << "NO\n";
            continue;
        }

        cout << (a[1] - a[0] == 1 ? "NO\n" : "YES\n");
    }
}