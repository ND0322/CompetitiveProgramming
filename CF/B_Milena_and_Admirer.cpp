#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        long long ans = 0;


        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int small = a[n-1];

        for(int i = n-2; i >= 0; i--){
            if(a[i] <= small){
                small = a[i];
                continue;
            }
            
            long long sz = (a[i]+small-1)/small;
            ans += sz-1;
            small = a[i]/sz;
            
        }

        cout << ans << "\n";


    }
}