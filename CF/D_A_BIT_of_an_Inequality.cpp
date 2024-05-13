#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

#define int long long

int n, a[MAXN], px[MAXN], l[35][2], r[35][2];

int msb(long long x){
    return 31 - __builtin_clz(x);
}

//count i such that f(l,r) ^ a[i] > f(l,r)
//msb of a[i] had to be both on in pref and suf or both off

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;
        
        for(int i = 0; i <= 34; i++){
            l[i][0] = 0;
            l[i][1] = 0;
            r[i][0] = 0;
            r[i][1] = 0;
        }

        
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            px[i] = px[i-1] ^ a[i];
        }

        

        for(int i = 1; i <= n;i++){
            
            for(int j = 0; j <= 30; j++){
                
                r[j][(bool)(px[i] & (1<<j))]++;
                l[j][0]=1;
            }
        }

        long long ans = 0;

        for(int i = 1; i <= n; i++){
            int bit = msb(a[i]);
            ans += l[bit][0] * r[bit][0];
            ans += l[bit][1] * r[bit][1];

            for(int j = 0; j <= 30; j++){
                r[j][(bool)(px[i] & (1<<j))]--;
                l[j][(bool)(px[i] & (1<<j))]++;
            }

        }

        cout << ans << "\n";
    }
}
