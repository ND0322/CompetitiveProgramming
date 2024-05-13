#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long n, k; cin >> n >> k;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.rbegin(), a.rend());

        long long sm = 0;

        int ans = 0;

        for(int i = 0; i < n; i++){
            sm += a[i];

            if(sm < k * (i+1)) break;
            ans = i+1;
        }

        cout << ans << "\n";

    }
}