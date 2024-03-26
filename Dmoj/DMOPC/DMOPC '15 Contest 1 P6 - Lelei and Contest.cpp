#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//a^p ≡ a (mod p)
//so basically the question is range add range sum and mod after or during doesnt really matter
//im gonna be lazy and mod after but ill change it if needed

const int MAXN = 2e5+5;

#define int long long
int n, q, MOD;

struct Node{
    long long sum, lz;
} st[MAXN<<2];

void pushdown(int node, int l, int r){
  if(!st[node].lz|| l == r) return;

  int mid = (l+r)>>1;

  st[node<<1].lz += st[node].lz;
  st[node<<1|1].lz += st[node].lz;
  st[node<<1].sum += (mid-l+1) * st[node].lz;
  st[node<<1|1].sum += (r-mid) * st[node].lz;
  st[node].lz = 0;
}

void build(int node, int l, int r){
    st[node].lz = 0;

    if(l == r){
        cin >> st[node].sum;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r); 
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

void update(int node, int l, int r, int x, int y, int v){
    if(x > r || y < l) return;

    
    if(x <= l && y >= r){
        st[node].sum += (r-l+1) * v;
        st[node].lz += v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r);
    update(node<<1,l,mid,x,y,v);
    update(node<<1|1,mid+1,r,x,y,v);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

long long query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sum;
    
    int mid = (l+r)>>1;
    pushdown(node,l,r);
    return query(node<<1,l,mid,x,y) + query(node<<1|1,mid+1,r,x,y);
}

int32_t main(){
    cin >> MOD >> n >> q;

    build(1,1,n);

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int l,r,x; cin >> l >> r >> x;
            update(1,1,n,l,r,x);
        }
        else{
            int l,r; cin >> l >> r;
            cout << query(1,1,n,l,r) % MOD << "\n";
        }

        //for(int i = 1; i <= n; i++) cout << query(1,1,n,i,i) << " ";
        //cout << "\n";
    }

   
}