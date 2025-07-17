#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

//3 pointers
//or 2p with one bsearch 

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, ts, tx; cin >> n >> ts >> tx;

        map<int,int> freq;

        vector<int> a(n+1), psa(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) psa[i] = a[i] + psa[i-1];
        int r1 = 0,r2 = 0;

        int ans = 0;

        for(int l = 1; l <= n; l++){

            while(r1 < l){
                freq[psa[r1]] = max(freq[psa[r1]]-1, 0LL);
                r1++;
            }
            r1 = max(l, r1);

            while(r1 <= n && a[r1] < tx){
                
                freq[psa[r1]] = max(freq[psa[r1]]-1, 0LL);
                r1++;
            }

            r2 = max(r1, r2);
        

            while(r2 <= n && a[r2] <= tx){
                freq[psa[r2]]++;
                r2++;
            }

            //psa[x] - psa[l-1] = ts
            //psa[x] = ts + psa[l-1]

            if(a[l] > tx) continue;
            
            //cout << l << " " << r1 << " " << r2 << " " << freq[ts + psa[l-1]] << " " << ts + psa[l-1] << "\n";

            ans += freq[ts + psa[l-1]];
        }

        cout << ans << "\n";
    }
}