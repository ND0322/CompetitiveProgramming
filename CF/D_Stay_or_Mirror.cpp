#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
the contribution of flipping would have already been added so it doesnt matter

if we flip we already calculate the inversions of all later things and when we flip later it saves an inversion on thr left 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n; 

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        long long ans = 0;

        for(int i = 1; i <= n; i++){
            int l = 0,r = 0;

            for(int j = 1; j < i; j++) l += (a[j] > a[i]);
            for(int j = i+1; j <= n; j++) r += (a[j] > a[i]);

            ans += min(l,r);
        }

        cout << ans << "\n";
    }
}