#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], b[MAXN], s[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];
        int p = 0;

        for(int i = 1; i <= n; i++){
            p = max(a[i], p);
            b[i] = p;
        }
        long long ans = 0;
        int big = 0;


        for(int i = 1; i <= n; i++){
            ans += b[i] - a[i];
            big = max(b[i] - a[i], big);
            
        }

        cout << ans+big << "\n";

    }
}