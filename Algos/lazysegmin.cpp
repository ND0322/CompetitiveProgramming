#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;



int n, q;

struct Node{
    long long val, lzAdd, lzSet;
    Node(){};
} st[MAXN<<2];

void pushdown(int node){


    if(st[node].lzSet){
        st[node<<1].lzSet = st[node<<1|1].lzSet = st[node].lzSet;
        st[node<<1].lzAdd = st[node<<1|1].lzAdd = 0;
        st[node<<1].val = st[node<<1|1].val = st[node].lzSet;
    }

    if(st[node].lzAdd){
        st[node<<1].lzAdd += st[node].lzAdd;
        st[node<<1|1].lzAdd += st[node].lzAdd;
        st[node<<1].val += st[node].lzAdd;
        st[node<<1|1].val += st[node].lzAdd;
    }

    st[node].lzAdd = st[node].lzSet = 0;
}

void build(int node, int l, int r){
    st[node].lzAdd = st[node].lzSet = 0;
    

    if(l == r){
        cin >> st[node].val;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
    st[node].val = min(st[node<<1].val, st[node<<1|1].val);

}

void add(int node, int l, int r, int x, int y, long long val){
    
    

    if(x == l && y == r){
        st[node].val += val;
        st[node].lzAdd += val;
        return;
    }

    int mid = (l+r)>>1;

    pushdown(node);
    if(y <= mid) add(node<<1, l, mid, x, y, val);
    else if(x > mid) add(node<<1|1, mid+1, r, x, y, val);
    else add(node<<1, l, mid, x, mid, val), add(node<<1|1, mid+1, r, mid+1, y, val);
    st[node].val = min(st[node<<1].val , st[node<<1|1].val);
}

void Set(int node, int l, int r, int x, int y, long long val){
    

    if(x == l && y == r){
        st[node].val = val;
        st[node].lzAdd = 0;
        st[node].lzSet = val;
        return;
    }

    int mid = (l+r)>>1;

    pushdown(node);
    if(y <= mid) Set(node<<1, l, mid, x, y, val);
    else if(x > mid) Set(node<<1|1, mid+1, r, x, y, val);
    else Set(node<<1, l, mid, x, mid, val), Set(node<<1|1, mid+1, r, mid+1, y, val);
    st[node].val = min(st[node<<1].val , st[node<<1|1].val);
}

long long query(int node, int l, int r, int x, int y){
    
    if(x == l && y == r) return st[node].val;
    int mid = (l+r)>>1;
    pushdown(node);
    if(y <= mid) return query(node<<1, l, mid, x, y);
    else if(x > mid) return query(node<<1|1, mid+1, r, x, y);
    else return min(query(node<<1, l, mid, x ,mid), query(node<<1|1, mid+1, r, mid+1, y));
    
}

int main(){
    cin >> n >> q;

    

    build(1,1,n);

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int l,r,x; cin >> l >> r >> x;
            add(1,1,n,l,r,x);
        }
        if(t == 2){
            int l, r, x; cin >> l >> r >> x;
            Set(1,1,n,l,r,x);
        }
        if(t==3){
            int l,r; cin >> l >> r;
            cout << query(1,1,n,l,r) << "\n";
        }
    }
}