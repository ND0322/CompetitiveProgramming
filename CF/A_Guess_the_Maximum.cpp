#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int ans = 1e9;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < n-1; i++) ans = min(ans, max(a[i],a[i+1]));
        cout << ans-1 << "\n";
    }
}