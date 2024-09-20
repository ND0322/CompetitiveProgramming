#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int>a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        //ai can be part of array with up to ai elements on the left 

        int ans = 0;

        int pmn = 1e9;
        for(int i = 1; i <= n; i++){
            pmn = min(i, pmn);
            ans += min(pmn, a[i]);
            pmn = min(pmn, a[i]);
        }

        cout << ans << "\n";

    }
}