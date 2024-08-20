#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.rbegin(), a.rend());

        //a will pick the odd numbers and b will pick even in the sorted thing

        int sm = 0;
        int b = 0;
        for(int i = 0; i < n; i++){
            if(!(i&1)){
                sm += a[i];
                continue;
            }

            b += min(a[i]+k, a[i-1]);
            k -= min(a[i]+k, a[i-1]) - a[i];
        }

        cout << sm - b << "\n";


    }
}