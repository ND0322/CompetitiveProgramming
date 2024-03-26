#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<int> a(n+m);

        for(int i = 0; i < n+m; i++) cin >> a[i];

        sort(a.begin(), a.end()-1);
        reverse(a.begin(),a.end());

        long long ans = 0;

        for(int i = 0; i < n; i++) ans += a[i];
        cout << ans << "\n";


    }
}