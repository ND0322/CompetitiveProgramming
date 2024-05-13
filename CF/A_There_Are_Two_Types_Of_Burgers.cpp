#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long a,b,c; cin >> a >> b >> c;
        long long x,y; cin >> x >> y;

        long long ans = 0;

        for(int i = 0; i <= min(a/2, b); i++) ans = max(ans, i * x + min(a/2 - i, c) * y);
        cout << ans << "\n";
    }
}