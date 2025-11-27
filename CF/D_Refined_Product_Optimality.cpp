#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int MOD = 998244353;

#define int long long

long long binpow(long long a, long long b){
    long long res = 1;

    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
        
    }
    return res;
}

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        int n,q; cin >> n >> q;

        vector<int> a(n+1), b(n+1), c(n+1), d(n+1);

        map<int,set<int, greater<int>>> mpa, mpb;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            c[i] = a[i];
            
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
            d[i] = b[i];
        }


        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        for(int i = 1; i <= n; i++){
            mpa[c[i]].insert(i);
            mpb[d[i]].insert(i);
        }

        int ans = 1;


        for(int i = 1; i <= n; i++) ans = (ans * min(c[i], d[i])) % MOD;

        cout << ans << " ";



        while(q--){
            int t,x; cin >> t >> x;
            int i;

            
            if(t == 1){
                i = *(mpa[a[x]].begin());
                mpa[a[x]].erase(mpa[a[x]].begin());
                a[x]++;

                
                mpa[a[x]].insert(i);

                ans = (ans * binpow(min(c[i], d[i]),MOD-2)) % MOD;
                c[i]++;
                ans = (ans * min(c[i], d[i])) % MOD;
            }
            else{
                i = *(mpb[b[x]].begin());
                mpb[b[x]].erase(mpb[b[x]].begin());
                b[x]++;                
                mpb[b[x]].insert(i);

                ans = (ans * binpow(min(c[i], d[i]),MOD-2)) % MOD;
                d[i]++;
                ans = (ans * min(c[i], d[i])) % MOD;
            }


            cout << ans << " ";

        
        }

        

        cout << "\n";

        
    }
}