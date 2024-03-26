#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], psa[MAXN], k;

bool can(int x){
    for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + pow(-1, (a[i] < x));

    int mn = 0;
    int ans = 0;

    for(int i = k; i <= n; i++){
        mn = min(mn, psa[i-k]);

        ans = max(ans, psa[i] - mn);
    }

    return ans > 0;
}

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int lo = 1;
    int hi = n; 
    int ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    cout << ans << "\n";
}