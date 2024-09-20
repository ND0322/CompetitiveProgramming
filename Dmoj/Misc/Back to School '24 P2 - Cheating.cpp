#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e6+5;

int ans[MAXN], n, m, a[MAXN], b[MAXN];

struct Node{
    long long mn, mx, sum, lzAdd, lzSet;
    Node(){};
} st[MAXN<<2];

void pushdown(int node, int l, int r, int mid){
    if(st[node].lzSet){
        st[node<<1].lzSet = st[node<<1|1].lzSet = st[node].lzSet;
        st[node<<1].lzAdd = st[node<<1|1].lzAdd = 0;
        st[node<<1].mn = st[node<<1|1].mn = st[node].lzSet;
        st[node<<1].mx = st[node<<1|1].mx = st[node].lzSet;

        if(l != r){
            st[node<<1].sum = st[node].lzSet * (mid-l+1);
            st[node<<1|1].sum = st[node].lzSet * (r-mid);
        }
        
    }

    if(st[node].lzAdd){
        st[node<<1].lzAdd += st[node].lzAdd;
        st[node<<1|1].lzAdd += st[node].lzAdd;
        st[node<<1].mn += st[node].lzAdd;
        st[node<<1|1].mn += st[node].lzAdd;
        st[node<<1].mx += st[node].lzAdd;
        st[node<<1|1].mx += st[node].lzAdd;
        if(l != r){
            st[node<<1].sum += st[node].lzAdd * (mid-l+1);
            st[node<<1|1].sum += st[node].lzAdd * (r-mid);
        }
    }

    st[node].lzAdd = st[node].lzSet = 0;
}

void build(int node, int l, int r){
    if(l == r){
        st[node].mn = a[l];
        st[node].sum = a[l];
        st[node].mx = a[l];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1,mid+1,r);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

void add(int node, int l, int r, int x, int y, long long v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn += v;
        st[node].mx += v;
        st[node].sum += (r-l+1)*v;
        st[node].lzAdd += v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    add(node<<1, l, mid, x, y, v);
    add(node<<1|1, mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

void update(int node, int l, int r, int x, int y, long long v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn = v;
        st[node].mx = v;
        st[node].sum = (r-l+1)*v;
        st[node].lzAdd = 0;
        st[node].lzSet = v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    update(node<<1,l,mid,x,y,v);
    update(node<<1|1,mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

long long qmn(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e18;
    if(x <= l && y >= r) return st[node].mn;
    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    return min(qmn(node<<1, l, mid, x,y), qmn(node<<1|1,mid+1,r,x,y));
}

long long qmx(int node, int l, int r, int x, int y){
    if(x > r || y < l) return -1e18;
    if(x <= l && y >= r) return st[node].mx;
    int mid = (l+r)>>1;
    pushdown(node,l, r, mid);
    return max(qmx(node<<1,l,mid,x,y), qmx(node<<1|1,mid+1,r,x,y));
}

long long qsm(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sum;
    int mid = (l+r)>>1;
    pushdown(node,l,r,mid);
    return qsm(node<<1,l,mid,x,y) + qsm(node<<1|1,mid+1,r,x,y);
}

int32_t main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    int p = 1;

    for(int i = 1; i <= n; i++){
        if(p + b[i] > m){
            add(1,1,m, p, m, a[i]);
            b[i] -= (m-p+1);
            p = 1;
            add(1, 1, m, p, p + b[i] - 1, a[i]);
            p += b[i];
        }
        else{
            add(1,1,m, p, p + b[i] - 1, a[i]);
            p += b[i];
        }
    }

    for(int i = 1; i <= m; i++) cout << qsm(1,1,m, i,i) << " ";
    cout << "\n";
}