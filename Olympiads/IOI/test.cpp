#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e6+5;
const int INF = 1e9;

int n,q, ans[MAXN];

struct Node{
    int mn, mx, lz1, lz2;
} st[MAXN<<2];

void pushdown(int node){
    if(st[node].lz1 != -INF){
        st[node<<1].mn = max(st[node<<1].mn, st[node].lz1);
        st[node<<1|1].mn = max(st[node<<1|1].mn, st[node].lz1);
        st[node<<1].mx = max(st[node<<1].mx, st[node].lz1);
        st[node<<1|1].mx = max(st[node<<1|1].mx, st[node].lz1);
        st[node<<1].lz1 = max(st[node<<1].lz1, st[node].lz1);
        st[node<<1|1].lz1 = max(st[node<<1|1].lz1, st[node].lz1);
        st[node<<1].lz2 = max(st[node<<1].lz2, st[node].lz2);
        st[node<<1|1].lz2 = max(st[node<<1|1].lz2, st[node].lz2);
    }
    if(st[node].lz2 != INF){
        st[node<<1].mn = min(st[node<<1].mn, st[node].lz2);
        st[node<<1|1].mn = min(st[node<<1|1].mn, st[node].lz2);
        st[node<<1].mx = min(st[node<<1].mx, st[node].lz2);
        st[node<<1|1].mx = min(st[node<<1|1].mx, st[node].lz2);
        st[node<<1].lz1 = min(st[node<<1].lz1, st[node].lz1);
        st[node<<1|1].lz1 = min(st[node<<1|1].lz1, st[node].lz1);
        st[node<<1].lz2 = min(st[node<<1].lz2, st[node].lz2);
        st[node<<1|1].lz2 = min(st[node<<1|1].lz2, st[node].lz2);
    }

    st[node].lz1 = -INF;
    st[node].lz2 = INF;
}

void update(int node, int l, int r, int x, int y, int k, bool t){
    if(x > r|| y < l) return;

    if(x <= l && y >= r){
        if(t){
            st[node].mn = max(st[node].mn, k);
            st[node].mx = max(st[node].mx, k);
            st[node].lz1 = max(st[node].lz1, k);
            st[node].lz2 = max(st[node].lz2, k);
        }
        else{
            st[node].mn = min(st[node].mn, k);
            st[node].mx = min(st[node].mx, k);
            st[node].lz1 = min(st[node].lz1, k);
            st[node].lz2 = min(st[node].lz2, k);
        }

        return;
    }

    int mid = (l+r)>>1;
    pushdown(node);
    update(node<<1,l,mid, x, y, k, t);
    update(node<<1|1, mid+1, r, x, y, k, t);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
}

void query(int node, int l, int r){
    pushdown(node);
    if(l == r){
        ans[l] = st[node].mx;
        return;
    }
    int mid = (l+r)>>1;
    query(node<<1, l, mid);
    query(node<<1|1, mid+1, r);
}

int main(){
    cin >> n >> q;

    for(int i = 0; i <= n<<2; i++) st[i] = {0,0-INF,INF};

    while(q--){
        bool t; cin >> t;
        int l,r,x; cin >> l >> r >> x;

        update(1,1,n, l+1,r+1, x, t);
    }

    query(1,1,n);

    for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
   

}