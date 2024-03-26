#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(),a.end());

        long long ans = a[0]+1;

        for(int i = 1; i < n; i++){
            ans *= a[i];
        }

        cout << ans << "\n";

        
    }
}