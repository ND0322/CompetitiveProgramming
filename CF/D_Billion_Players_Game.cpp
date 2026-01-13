#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+10;

#define int long long

int n, l, r, a[MAXN], psa[MAXN];


/*
some prefix will be option 2
some suffix will be option 1

the worst answer will be at the left or right endpoint

each move left in the prefix is -2

iterate over l and ternary search on r 
*/


int f(int pref, int suf){

    int opt1 = l * pref - psa[pref] + psa[n] - psa[suf-1] - (n-suf+1) * l;
    int opt2 = r * pref - psa[pref] + psa[n] - psa[suf-1] - (n-suf+1) * r; 
    return min(opt1, opt2);
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> l >> r;

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a+1, a+n+1);

        for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + a[i];

        int ans = 0;

        for(int i = 0; i <= n; i++){
            int lo = i+1;
            int hi = n+1;

            int best = i+1;

            while(lo <= hi){
                int mid = (lo+hi)>>1;
                if(f(i,mid) >= f(i, mid+1)){
                    hi = mid-1;
                    best = mid;
                }
                else lo = mid+1;
            }
            

            ans = max(ans, f(i,best));
        }

        cout << ans << "\n";
    }
}