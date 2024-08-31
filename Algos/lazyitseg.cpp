#include <bits/stdc++.h>
#include <iostream>
#include <set>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

using namespace std;

const int MAXN = 5e5+5;

int n, m, q, lz[MAXN<<1],st[MAXN<<1];

bool h[MAXN<<1];


void push(int i) {

    if(h[i>>1]){
        st[i] = lz[i>>1];
        lz[i] = lz[i>>1];
        h[i] = 1;

        st[i^1] = lz[i>>1];
        lz[i^1] = lz[i>>1];
        h[i^1] = 1;

        h[i>>1] = 0;
    }
}

void pushdown(int i){
    int k = 0;
    for(; (i >> k) > 0; k++);
    for(k -= 2; k >= 0; k--) push(i>>k);
}

void pop(int i){
    if(h[i>>1]) st[i>>1] = lz[i>>1];
    else st[i>>1] = max(st[i], st[i^1]);
}

void popup(int i){
    for(; i > 1; i>>=1) pop(i);
}

void update(int l, int r, int v){
    l += n;
    r += n;

    pair<int,int> tmp = {l,r};

    pushdown(l);
    pushdown(r);

    for(; l < r; l >>=1, r>>=1){
        if(l&1){
            st[l] = v;
            lz[l] = v;
            h[l] = 1;
            l++;
        }
        if(r&1){
            r--;
            st[r] = v;
            lz[r] = v;
            h[r] = 1;
        }
    }

    popup(tmp.first);
    popup(tmp.second);
}

int query(int l, int r){
    l += n;
    r += n;

    pushdown(l);
    pushdown(r);

    int ans = 0;

    for(; l < r; l >>=1, r>>=1){
        if(l&1) ans = max(ans, st[l++]);
        if(r&1) ans = max(ans, st[--r]);
    }

    return ans;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin >> n >> q;

    while(q--){
        int l,r,v; cin >> l >> r >> v;

        update(l,r+1,v);

        for(int i = 1; i <= n; i++) cout << query(i,i+1) << " ";
        cout << "\n";


    }

}