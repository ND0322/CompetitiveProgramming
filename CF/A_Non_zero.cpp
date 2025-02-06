#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        int sm = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(!a[i]){
                
                a[i] += 1;
                ans++;
            }
            sm += a[i];
        }

        if(sm == 0) ans++;
        cout << ans << "\n";




    }
}