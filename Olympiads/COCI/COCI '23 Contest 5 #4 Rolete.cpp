#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long 

const int MAXN = 1e5+5;

int n, t,s, k, q, h, psa[MAXN], ssa[MAXN], a[MAXN];




long long f(int x){

    long long ans = x * s;


    //lower bound is giving me a stroke so og we go

    int lo = 1;
    int hi = n;

    int pos = 0;
    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(x > a[mid]){
            pos = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    
    ans += pos * x * k - psa[pos] * k;
    
    lo = 1;
    hi = n;

    pos = 0;
    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(a[mid] > h+x){
            pos = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    if(!pos) return ans;

    ans += (ssa[pos] - (h+x) * (n-pos+1)) * t;

    return ans;
}

int32_t main(){
    cin >> n >> t >> s >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1,a+n+1);

    for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + a[i];
    for(int i = n; i >= 0; i--) ssa[i] = ssa[i+1] + a[i];
    
    cin >> q;

    while(q--){
        cin >> h;

        int lo = 0;
        int hi = 1e5;

        long long ans = 0;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(f(mid) <= f(mid+1)){
                ans = f(mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }

        cout << ans << " ";
    }
    
    
    
    

    
}