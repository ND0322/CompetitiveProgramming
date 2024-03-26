#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

//b is a dogsh question

const int MAXN = 3e5+5;

int n, q, a[MAXN], psa[MAXN], cnt[MAXN];

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> q;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            psa[i] = psa[i-1] + a[i];
            cnt[i] = cnt[i-1] + (a[i] == 1);
        }

        while(q--){
            int l,r; cin >> l >> r;

            int sum = psa[r] - psa[l-1];

            sum -= (r-l+1);
            
            if(l == r){
                cout << "NO\n";
                continue;
            }
            if(sum >= cnt[r] - cnt[l-1]) cout << "YES\n";
            else cout << "NO\n";          
        }
    }
}