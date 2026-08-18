#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int cnt[3] = {0,0,0};

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            cnt[x]++;
        }

        int ans = cnt[0];
        int tmp = min(cnt[1], cnt[2]);

        ans += tmp;

        cnt[1] -= tmp;
        cnt[2] -= tmp;

        ans += cnt[1]/3;
        ans += cnt[2]/3;

        cout << ans << "\n";
    }
}