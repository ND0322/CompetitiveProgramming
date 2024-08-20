#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, q, a[MAXN], psa[MAXN];

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n-2; i++) psa[i] = psa[i-1] + (a[i] >= a[i+1] && a[i+1] >= a[i+2]);
    while(q--){
        int l, r; cin >> l >> r;
        
        if(r-l+1 < 3){
            cout << r-l+1 << "\n";
            continue;
        }
        
        cout << r-l+1 - (psa[r-2] - psa[l-1]) << "\n";
    }
}