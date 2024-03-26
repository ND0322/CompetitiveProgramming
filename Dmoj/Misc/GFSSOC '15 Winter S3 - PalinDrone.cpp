#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1e9;


int main(){
    int n; cin >> n;
    long long ans = 0;
    long long cnt = -1;

    for(int i = 1; i <= n; i++){
        if(cnt >= 9) break;
        if(i&1) cnt++;

        ans = (ans + (9 * (long long)pow(10,cnt))) % MOD;
    }

    cout << ans << "\n";
}