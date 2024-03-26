#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        //sliding window

        int ans = 0;
        int r = 0;

        for(int i = 0; i < a.size(); i++){
            while(a[i] - a[r] >= n) r++;
            ans = max(ans, i-r+1); 
        }

        cout << ans << "\n";

    
    }
}