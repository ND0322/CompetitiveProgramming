#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;


struct Node{
    int lz = 0, mx= 0;
} st[MAXN<<2];

void pushdown(int node, int l, int r, int mid){

    if(!st[node].lz) return;
    st[node<<1].lz += st[node].lz;
    st[node<<1|1].lz += st[node].lz;
    st[node<<1].mx += st[node].lz;
    st[node<<1|1].mx += st[node].lz;

    st[node].lz = 0;
}

void build(int node, int l, int r){
    st[node].lz = 0;
    st[node].mx = 0;
    if(l == r){
        st[node].mx = 0;
        st[node].lz = 0;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
}

void update(int node, int l, int r, int x, int y, int v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].lz += v;
        st[node].mx += v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    update(node<<1, l, mid, x, y, v);
    update(node<<1|1, mid+1,r,x,y,v);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].mx;

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    return max(query(node<<1, l, mid ,x, y), query(node<<1|1, mid+1,r,x,y));
}


/*
let ans[i] be ans if mex is i

ans[a[i]] is 0 because it will always include a[i]

anything less than a[i] will get contributed +1
anything more will get nothing 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        build(1,0,n);

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i <= n; i++){
            update(1,0,n,0, a[i]-1,1);
            update(1,0,n,a[i], a[i], -query(1,0,n, a[i], a[i]));

            cout << query(1, 0, n, 0, n) << " ";
        }

        cout << "\n";
    }
}