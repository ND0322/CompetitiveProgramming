#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
first decreasing then increasing
*/


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+3);

        for(int i = 1; i <= n; i++) cin >> a[i];

        int ans = 0;

        for(int i = 2; i <= n-1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                a[i+1] = max(a[i], a[i+2]);
                ans++;
            }
        }

        cout << ans << "\n";

        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}