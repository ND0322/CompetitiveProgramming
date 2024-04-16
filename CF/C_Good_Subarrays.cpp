#include <bits/stdc++.h>
#include <iostream>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;

const int MAXN = 1e5+5;

int n, psa[MAXN];

string s;

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        cin >> s;
        for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + s[i-1] - '0';
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n;j++){
                ans += (psa[j] - psa[i-1] == j-i+1);
            }
        } 

        cout << ans << "\n";
    }
}

