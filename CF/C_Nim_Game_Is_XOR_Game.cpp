#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
at most one nonzero element
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        if(n == 1){
            cout << "0\n";
            continue;
        }

        int ans = 0;

        int x = 0;

        for(int i = 1; i <= n; i++) x ^= a[i];

        if(x == 0){
            cout << "1\n";
            continue;
        }
        for(int i = 1; i <= n; i++) ans += (x ^ a[i]) < a[i];

        cout << ans << "\n";
    }
}

