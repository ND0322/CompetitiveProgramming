#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int ans = 1e9;
        for(int i = 0; i <= n; i++) ans = min(ans, i + max((n - 4*i),0) / 2);

        cout << ans << "\n";
    }
}