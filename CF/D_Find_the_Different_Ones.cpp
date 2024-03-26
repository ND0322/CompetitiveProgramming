#include <bits/stdc++.h>
#include <iostream>
#include <map>


using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], psa[MAXN];



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        
        int n; cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 2; i <= n; i++){
            psa[i] = psa[i-1] + abs(a[i] - a[i-1]);
            //cout << psa[i] << " ";
        }

        //cout << "\n";

        int q; cin >> q;

        while(q--){
            int l,r; cin >> l >> r;
            
            if(psa[r] - psa[l] == 0){
                cout << "-1 -1\n";
                continue;
            }

            int lo = l+1;
            int hi = r;
            int ans = -1;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(psa[mid] - psa[l] != 0){
                    ans = mid;
                    hi = mid-1;
                }
                else lo = mid+1;
            }

            cout << l << " " << ans << "\n";

        }

    }
    


}