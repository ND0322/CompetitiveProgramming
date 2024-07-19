#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long



const int MAXN = 2e6+5;

int q, k,n, st[MAXN<<1], ans, a[MAXN], upd;

bool removed[MAXN];


void update(int i, int x){
    for(st[i+=2e6] += x; i > 1; i >>=1) st[i>>1] = st[i] + st[i^1];
}

int query(int l, int r){
    int ans = 0;
    for(l += 2e6, r+=2e6; l < r; l >>=1, r>>=1){
        if(l&1) ans += st[l++];
        if(r&1) ans += st[--r];
    }
    return ans;
}

int32_t main(){
    cin >> q >> k;


    

    int cnt = 0;

    while(q--){
        char c; cin >> c;

        if(c == 'I'){
            int x; cin >> x;

            
            
            
            if(x < k)removed[n] = 1;
            else update(x, 1);
            a[n] = x;

            n++;
            
        }

        if(c == 'F'){
            int x; cin >> x;

            if(x > n-cnt){
                cout << "-1\n";
                continue;
            }

            int lo = 0;
            int hi = 2e6;

            int ans = -1;


            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(query(mid,2e6) >= x){
                    ans = mid;
                    lo = mid+1;
                }
                else hi = mid-1;
            }

            

            cout << ans << "\n";
        }

        if(c == 'A'){
            int x; cin >> x;

            for(int i = 0; i < n; i++){
                if(removed[i]) continue;
                
                update(a[i], -1);
                update(a[i] + x, 1);
                a[i] += x;
            }
        }

        if(c == 'S'){
            int x; cin >> x;


            for(int i = 0; i < n; i++){
                if(removed[i]) continue;
                update(a[i], -1);
                if(a[i] - x < k){
                    removed[i] = 1;
                    cnt++;
                    continue;
                }
                update(a[i] - x, 1);
                a[i] -= x;
            }

           
            

        }
    }

    cout << cnt << "\n";



   
   

    
}