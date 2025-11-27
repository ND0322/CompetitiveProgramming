#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

/*
sum range where sum < n * (l+r)
sum < (r-l+1) * (l+r)
psa[r] - psa[l-1] 
(r-l+1) * (l+r) - psa[r] + psa[l-1]

r^2 + rl -l^2 - rl +l + r
r^2 - l^2 + l + r

r^2 + r - psa[r] + psa[l-1] - l^2 + l

for some r we want the max value of psa[l-1] - l^2 + l

psa[n] - (psa[r] - psa[l-1]) + r^2 + r - psa[r] + psa[l-1] - l^2 + l

psa[n] - 2psa[r] + 2psa[l-1] + r^2 + r - l^2 + l
at some point its better do the whole array
*/


int32_t main(){
    int tt; cin >> tt;
    

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        vector<int> psa(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + a[i];

        int mx = 0;
        int ans = 0;

        for(int i = 1; i <= n; i++){
            mx = max(mx, psa[i-1] - i * i + i);


            ans = max(ans, - psa[i] + i * i + i + mx);
        }

        cout << psa[n] + ans << "\n";


    }
}