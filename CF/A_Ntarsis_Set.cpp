#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

typedef long long ll;

int n,k;

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        vector<ll> a(n);

        ll ans = 1;

        for(int i = 0; i < n ; i++){
            cin >> a[i];
        }

        while(k--){
            ll lo = ans;
            ll hi = 1e12;

            while(lo < hi){
                ll mid = (lo+hi)>>1;

                int nxt = (int) (upper_bound(a.begin(),a.end(),mid)-a.begin());

                if(mid - nxt >= ans){
                    hi = mid;
                }
                else{
                    lo = mid+1;
                }

                
            }
            ans = lo;
        }

        cout << ans << "\n";
    }
}