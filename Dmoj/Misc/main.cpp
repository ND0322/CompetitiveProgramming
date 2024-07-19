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
    long long val, lzAdd, lzSet;
    Node(){};
} st[MAXN<<2];

void pushdown(int node, int l, int r){
    int mid = (l+r)>>1;

    if(st[node].lzSet){
        st[node<<1].lzSet = st[node<<1|1].lzSet = st[node].lzSet;
        st[node<<1].val = (mid - l + 1) * st[node].lzSet;
        st[node<<1|1].val = (r-mid) * st[node].lzSet;
        st[node<<1].lzAdd = st[node<<1|1].lzAdd = 0;
        st[node].lzSet = 0;
    }

    else if(st[node].lzAdd){
        if(!st[node<<1].lzSet) st[node<<1].lzAdd += st[node].lzAdd;
        else{
            st[node<<1].lzSet += st[node].lzAdd;
            st[node<<1].lzAdd = 0;
        }

        if(!st[node<<1|1].lzSet) st[node<<1|1].lzAdd += st[node].lzAdd;
        else{
            st[node<<1|1].lzSet += st[node].lzAdd;
            st[node<<1|1].lzAdd = 0;
        }

        st[node<<1].val += (mid-l+1) * st[node].lzAdd;
        st[node<<1|1].val += (r-mid) * st[node].lzAdd;
        st[node].lzAdd = 0;
    }
}

void build(int node, int l, int r){
    st[node].lzAdd = st[node].lzSet = 0;
    

    if(l == r){
        st[node].val = a[l];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
    st[node].val = st[node<<1].val + st[node<<1|1].val;

}

void add(int node, int l, int r, int x, int y, long long val){
    if(x > r || y < l) return;

    if(x == l && y == r){
        st[node].val += (r-l+1) * val;
        if(!st[node].lzSet) st[node].lzAdd += val;
        else st[node].lzSet += val;
        return;
    }

    int mid = (l+r)>>1;

    pushdown(node, l, r);
    add(node<<1, l, mid, x, y, val);
    add(node<<1|1, mid+1, r, x, y, val);
    st[node].val = st[node<<1].val + st[node<<1|1].val;
}


long long query(int node, int l, int r, int x, int y){
    if(x >r || y < l) return 0;
    if(x <= l && y >= r) return st[node].val;
    int mid = (l+r)>>1;
    pushdown(node, l, r);
    return query(node<<1, l, mid, x, y) + query(node<<1|1, mid+1, r, x , y);
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

    cout << q << "\n";

    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);

    long long ans = 1e18;
    for(int _ = 1; _ <= q; _++){
        int l,r,x; cin >> l >> r >> x;
        if(prime[_]) ans = min(ans, _ * (query(1,1,n,l,r) + x));
        else add(1,1,n,l,r,x);
    }

    cout << ans << "\n";
}

