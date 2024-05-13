#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int cnt[105];

        memset(cnt, 0, sizeof(cnt));

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            cnt[x]++;
        }

        int ans = 0;
        for(int i = 1; i <= 100; i++) ans += cnt[i]/3;
        cout << ans << "\n";

    }
}