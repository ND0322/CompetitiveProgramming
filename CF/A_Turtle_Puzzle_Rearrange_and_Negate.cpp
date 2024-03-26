#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        long long ans = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;
            ans += abs(x);
        }

        cout << ans << "\n";
    }
}