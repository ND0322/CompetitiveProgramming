#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, q, a[MAXN];

struct  Node{
    double sm, lz;
} st[MAXN<<2];


void pushdown(int node, int l, int r, int mid){
    if(!st[node].lz) return;

    st[node<<1].lz = st[node].lz;
    st[node<<1|1].lz = st[node].lz;

    if(l != r){
        st[node<<1].sm = st[node].lz * (mid-l+1);
        st[node<<1|1].sm = st[node].lz * (r-mid);
    }


    st[node].lz = 0;
}


void build(int node, int l, int r){
    if(l == r){
        st[node].sm = a[l];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1,mid+1,r);
    st[node].sm = st[node<<1].sm + st[node<<1|1].sm;
}

void update(int node, int l, int r, int x, int y, double v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].sm = (r-l+1) * v;
        st[node].lz = v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node,l,r,mid);
    update(node<<1, l, mid, x, y, v);
    update(node<<1|1, mid+1,r,x,y,v);
    st[node].sm = st[node<<1].sm + st[node<<1|1].sm;
}

double query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sm;

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    return query(node<<1,l, mid, x, y) + query(node<<1|1, mid+1, r, x , y);
}


int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];


   

    build(1,1,n);

    while(q--){
        string t; cin >> t;


        if(t == "shuffle"){
            int l,r; cin >> l >> r;

             int sm = 0;
             for(int i = l; i <= r; i++) sm += a[i];

            
            update(1,1,n,l,r, query(1,1,n,l,r) / (r-l+1));

            
        }
        else{
            int i; cin >> i;

            cout << setprecision(9) << fixed << query(1,1,n, i,i) << "\n";
        }
    }
}

