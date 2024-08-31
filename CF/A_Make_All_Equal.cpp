#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> cnt(n+1);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            cnt[x]++;
            ans = max(ans, cnt[x]);
        }

        cout << n-ans << "\n";

    }
}