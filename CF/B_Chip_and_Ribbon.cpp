#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        long long ans = 0;
        vector<int> a(n);
        for(int i = 0; i <n ; i++) cin >> a[i];

        for(int i = 1; i < n; i++) if(a[i] < a[i-1]) ans += a[i-1] - a[i];

        ans += a[n-1]-1;
        cout << ans << "\n";   
        

        
    }
}