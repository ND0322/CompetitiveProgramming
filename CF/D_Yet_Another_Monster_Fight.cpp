#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//binary search + dp to check

const int MAXN = 3e5+5;


int n, a[MAXN], pmax[MAXN], smax[MAXN];

bool can(long long x){
    if(smax[0] <= x || pmax[n-1] <= x) return true;

    for(int i = 1; i < n-1; i++) if(pmax[i-1] <= x-(n-i) && smax[i+1] <= x-i-1) return true;
    return false;
    
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    long long lo = 0;
    long long hi = 1500000000;
    long long ans = hi;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        lo = max(lo,(long long)a[i]);
    }
    

    pmax[0] = a[0];

    for(int i = 1; i < n; i++) pmax[i] = max(pmax[i-1]+1, a[i]);

    smax[n-1] = a[n-1];

    for(int i = n-2; i >= 0; i--) smax[i] = max(smax[i+1]+1,a[i]);

    
    

    while(lo <= hi){
        long long mid = (lo+hi)>>1;

        if(can(mid)){
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;
    }

    cout << ans << "\n";




}
