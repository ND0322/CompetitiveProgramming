#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e6+5;
const int INF = 1e9;

int n,q, ans[MAXN];

struct Node{
    int val, lz1, lz2;
} st[MAXN<<2];

void pushdown(int node, int l, int r){
    if(st[node].lz1 != -INF || st[node].lz2 != INF){
        st[node].val = max(st[node].lz1, st[node].val);
        st[node].val = min(st[node].lz2, st[node].val);

        if(l != r){
            st[node<<1].lz1 = min(max(st[node<<1].lz1, st[node].lz1), st[node].lz2);
            st[node<<1].lz2 = min(max(st[node<<1].lz2, st[node].lz1), st[node].lz2);
            st[node<<1|1].lz1 = min(max(st[node<<1|1].lz1, st[node].lz1), st[node].lz2);
            st[node<<1|1].lz2 = min(max(st[node<<1|1].lz2, st[node].lz1), st[node].lz2);
        }
        st[node].lz1 = -INF;
        st[node].lz2 = INF;
    }
}

void update(int node, int l, int r, int x, int y, int k, int t){
    pushdown(node, l, r);
    if(x > r|| y < l) return;
    if(x <= l && y >= r){
        if(t == 1){
            st[node].lz1 = k;
            st[node].lz2 = INF;
        }
        else{
            st[node].lz1 = -INF;
            st[node].lz2 = k;
        }
        return;
    }

    int mid = (l+r)>>1;
    update(node<<1,l,mid, x, y, k, t);
    update(node<<1|1, mid+1, r, x, y, k, t);
}

void query(int node, int l, int r){
    pushdown(node, l, r);
    if(l == r){
        ans[l] = st[node].val;
        return;
    }
    int mid = (l+r)>>1;
    query(node<<1, l, mid);
    query(node<<1|1, mid+1, r);
}

int main(){
    cin >> n >> q;

    while(q--){
        int t; cin >> t;
        int l,r,x; cin >> l >> r >> x;

        update(1,0,n-1, l,r, x, t);
    }

    query(1, 0,n-1);

    for(int i = 0; i < n; i++) cout << ans[i] << "\n";
   

}