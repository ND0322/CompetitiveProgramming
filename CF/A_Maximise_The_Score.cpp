#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(2*n);

        for(int i = 0; i < 2*n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int ans = 0;
        for(int i = 0; i < 2*n; i+=2) ans += a[i];
        cout << ans << "\n";

    }
}