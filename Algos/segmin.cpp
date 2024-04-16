#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;

long long a[MAXN], st[MAXN<<2];

void build(int node, int l, int r){
    if(l == r){
        cin >> a[l];
        st[node] = a[l];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

void update(int node, int l, int r, int i, long long x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i,x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

long long query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e18;
    if(x <= l && y >= r) return st[node];
    int mid =(l+r)>>1;
    return min(query(node<<1,l,mid, x,y), query(node<<1|1, mid+1,r,x,y));
}