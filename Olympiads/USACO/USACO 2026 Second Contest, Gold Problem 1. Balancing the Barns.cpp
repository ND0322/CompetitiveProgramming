#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 5e4+5;

int n, a[MAXN], b[MAXN];
long long k;

/*
each transfer fixes the answer by 2

if we can fix have differen 0 or 1 for each thing first 

number of distinct frequencies is sqrt n 

1 4 6 8 9
2 2 5 5 5 

bsearch on difference

some l such that each bi >= l and ai <= l + x

cost of each i = max(ai - l - x, l - bi)
*/

__int128 f(int l, int x){
    __int128 sm = 0;
    for(int i = 1; i <= n; i++){
        __int128 ff = (__int128) (a[i] - l - x);
        __int128 ss = (__int128) (l - b[i]);
        sm += max((__int128)0, max(ff, ss));
    }
    return (__int128)sm;
}
bool can(int x){
    
    int lo = -1e18;
    int hi= 2e18;

    while(lo < hi){
        int mid = lo + (hi - lo) / 2;

        if(f(mid, x) < f(mid+1, x)) hi = mid;
        else lo = mid+1;
    }

    return f(lo, x) <= k;
}
int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        
        
        cin >> n >> k;


        int mx = 0;
        int mn = 1e9;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
            mn = min(mn, b[i]);
        }

        int lo = -2e18;
        int hi = 2e18;

        int ans = mx - mn;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(can(mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        cout << ans << "\n";


        


    }
}