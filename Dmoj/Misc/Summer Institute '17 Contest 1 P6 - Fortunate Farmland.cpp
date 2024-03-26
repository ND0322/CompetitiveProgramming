#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;

long long k, a[MAXN];

bool can(long long x){
    long long cap = k;
    for(int i = 1; i <= n; i++){
        if(a[i] < x){
            if(x - a[i] > cap) return 0;
            cap -= (x-a[i]);
        }
    }

    return 1;
}

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];


    long long lo = 0;
    long long hi = 1e18;
    long long ans = -1;

    while(lo <= hi){
        long long mid = (lo+hi)>>1;

        if(can(mid)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    cout << ans << "\n";


}