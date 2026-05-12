#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], psa[MAXN];

int msb(int x){
    return 31-__builtin_clz(x);
}

bool p2(int x){
    return __builtin_popcount(x) != 1;
}
int f(int x, int l){
    int cnt1 = psa[l-1];
    int cnt2 = psa[x-1] - cnt1;
    int cnt3 = n - cnt1 - cnt2;

    cout << x << " " << l << " " << cnt1 << " " << cnt2 << " " << cnt3 << "\n";
    cout << ((msb(cnt1)+p2(cnt1) + !cnt1)<<1) << " " << ((msb(cnt2)+p2(cnt2) + !cnt2)<<1) << " " << ((msb(cnt3)+p2(cnt3) + !cnt3)<<1) << "\n";

    return ((msb(cnt1)+p2(cnt1))<<1) + ((msb(cnt2)+p2(cnt2))<<1) + ((msb(cnt3)+p2(cnt3))<<1);



}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) psa[i] = 0;
        for(int i= 1; i <= n; i++){
            cin >> a[i];
            psa[a[i]]++;
        }
        for(int i = 1; i <= n; i++) psa[i] += psa[i-1];
    
        
        int ans = 1e9;
        for(int i = 1; i <= n; i++){
            int lo = i+1;
            int hi = n;

            int best = -1;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(f(mid, i) >= f(mid+1, i)){
                    best = mid;
                    lo = mid+1;
                }
                else hi = mid-1;
            }

            if(best == -1) continue;

            ans = min(ans, f(best, i));
        }

        cout << ans << "\n";
        
    
        
    }
}