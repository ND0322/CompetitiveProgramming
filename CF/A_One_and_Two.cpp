#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            cnt += (a[i] == 2);
        }

        int ans =1e9;

        int l = 0;
        for(int i = 1; i < n; i++){
            l += (a[i-1] == 2);
            cnt -= (a[i-1] == 2);

            if(l == cnt) ans = min(ans, i);
        }

        cout << (ans == 1e9 ? -1 : ans) << "\n";

        
    }
}