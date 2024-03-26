#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,k,a[MAXN];

bool can(int x){
    long long ans = 0;

    for(int i = 0; i < n; i++){
        if(a[i] < x) ans += (x-a[i]);
    }

    return ans <= k;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        for(int i = 0; i < n; i++) cin >> a[i];

        long long lo = 1;
        long long hi = 1e18;
        int ans = -1;

        while(lo <= hi){
            long long mid = (lo+hi)/2;

            if(can(mid)){
                lo = mid+1;
                ans = mid;
            }
            else{
                hi = mid-1;
            }
        }

        cout << ans << "\n";
    }
}

