#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    int cnt = 0;
    int zero = 0;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        long long x; cin >> x;

        if(!x) zero++;
        if(x >= 0) ans += abs(1 - x);
        else{
            ans += abs(x) - 1;
            cnt++;
        }
    }

    if((cnt&1) && !zero) ans += 2;

    cout << ans << "\n";
}