#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        long long ans = 0;

        ans += n/15;
        n %= 15;

        ans += n/10;
        n %= 10;

        ans += n/6;
        n %= 6;

        ans += n/3;
        n %= 3;

        ans += n;

        cout << ans << "\n";

    }
}