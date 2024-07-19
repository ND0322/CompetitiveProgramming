#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;
const int MAXM = 1e5+5;

int n, a[MAXN];

bool prime[MAXM];

/*
checked against:
https://usaco.org/index.php?page=viewproblem2&cpid=578
https://cses.fi/problemset/task/1735/

*/

struct Node{
    long long sum, lzAdd;
    Node(){};
} st[MAXN<<2];

void pushdown(int node, int l, int r, int mid){

    if(st[node].lzAdd){
        st[node<<1].lzAdd += st[node].lzAdd;
        st[node<<1|1].lzAdd += st[node].lzAdd;
        if(l != r){
            st[node<<1].sum += st[node].lzAdd * (mid-l+1);
            st[node<<1|1].sum += st[node].lzAdd * (r-mid);
        }
    }

    st[node].lzAdd = 0;
}

void build(int node, int l, int r){
    if(l == r){
       
        st[node].sum = a[l];

        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1,mid+1,r);
    
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

void add(int node, int l, int r, int x, int y, long long v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){

        st[node].sum += (r-l+1)*v;
        st[node].lzAdd += v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    add(node<<1, l, mid, x, y, v);
    add(node<<1|1, mid+1,r,x,y,v);
    
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}


long long qsm(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sum;
    int mid = (l+r)>>1;
    pushdown(node,l,r,mid);
    return qsm(node<<1,l,mid,x,y) + qsm(node<<1|1,mid+1,r,x,y);
}

int main(){
    cin >> n;
    int q; cin >> q;

    memset(prime, 1, sizeof(prime));
    prime[1] = 0;

    for(int i = 2; i * i <= 1e5; i++){
        if(prime[i]){
            for(int j = i*i; j <= 1e5; j += i) prime[j] = 0;
        }
    }

    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    long long ans = 1e18;
    for(int _ = 1; _ <= q; _++){
        int l,r,x; cin >> l >> r >> x;
        if(prime[_]) ans = min(ans, _ * (qsm(1,1,n,l,r) + x));
        else add(1,1,n,l,r,x);
    }

    cout << ans << "\n";
}