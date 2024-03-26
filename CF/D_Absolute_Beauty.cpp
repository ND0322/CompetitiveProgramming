#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int>a(n);
        vector<int>b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];


        long long ans = 0;
        int l = 0;
        int r = 1e9;

        for(int i = 0; i < n; i++){
            ans += abs(a[i] - b[i]);
            l = max(l, min(a[i],b[i]));
            r = min(r, max(a[i],b[i]));
        }

        cout << ans + (l > r) * 2 * (l-r) << "\n";
    }
    
}