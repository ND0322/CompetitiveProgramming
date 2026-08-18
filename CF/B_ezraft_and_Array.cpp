#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        if(n == 2){
            cout << "-1\n";
            continue;
        }

        if(n == 1){
            cout << "1\n";
            continue;
        }

        vector<int> ans(n+1);
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 3;

        int pref = 6;
        for(int i = 4; i <= n; i++){
            ans[i] = pref;
            pref *= 2;
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}