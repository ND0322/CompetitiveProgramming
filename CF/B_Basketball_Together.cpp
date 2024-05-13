#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, k, a[MAXN];

int32_t main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    int r = n;
    int l = 1;
    int ans = 0;
    while(l <= r){
        int cur = a[l];

        while(cur <= k && r > l){
            r--;
            cur += a[l];
        }

       //cout << l << " " << r<< " " << cur << "\n";
        if(cur > k) ans++;
        l++;
    
        
    }

    cout << ans << "\n";
}