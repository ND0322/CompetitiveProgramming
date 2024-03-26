#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;
const int MOD = 998244353;

int n,a[MAXN];

int main(){
    cin >> n;

    long long ans = 0;
    int mul = 1;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i <= 30; i++){
        int cnt = 0;
        bool odd = 0;

        for(int j = 0; j < n; j++){
            if(a[j] & (1 << i)) odd = 1-odd;
               
            

            if(odd) cnt++;

        }
        for(int j = 0; j < n; j++){
            ans = (ans + ((mul * cnt) % MOD)) % MOD;

            if(a[j] & (1 << i)) cnt = (n-j-cnt);

        }

        mul *= 2;

    }

    cout << ans << "\n";
}