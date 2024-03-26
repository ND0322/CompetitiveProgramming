#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<bool> a(n);

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            a[i] = x&1;
        }

        int ans = 0;

        for(int i = 1; i < n; i++) ans += (a[i] == a[i-1]);

        cout << ans << "\n";
    }
}