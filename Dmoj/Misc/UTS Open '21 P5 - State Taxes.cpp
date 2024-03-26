#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;


int n, q;

struct Node{
    long long val, lz, sal;
} st[MAXN<<2];

void pushdown(int node, int l, int r){
    if(st[node].lz){
        st[node].val += st[node].lz * st[node].sal;

        if(l == r){
            st[node].lz = 0;
            return;
        }

        st[node<<1].lz += st[node].lz;
        st[node<<1|1].lz += st[node].lz;
        st[node].lz = 0;
    }
}
void build(int node, int l, int r){
    st[node].lz = 0;
    if(l == r){
        cin >> st[node].sal;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
}

void update(int node, int l, int r, int x, int y, int val){
    pushdown(node, l, r);
    if(x > r || y < l) return;

    if(x <= l && y >= r){
        st[node].sal += val;
        return;
    }
    int mid = (l+r)>>1;
    update(node<<1, l, mid, x, y, val);
    update(node<<1|1, mid+1, r, x, y, val);
}

void upd(int node, int l, int r, int x, int y, long long val){
    pushdown(node, l, r);
    if(x > r || y < l) return;

    if(x <= l && y >= r){
        st[node].val += val;
        st[node].val += st[node].sal;
        if(l != r){
            st[node<<1].lz += 1;
            st[node<<1|1].lz += 1;
        }
       st[node].lz = 0;
       return;
    }
    int mid = (l+r)>>1;
    upd(node<<1, l, mid, x,y, val + st[node].sal);
    upd(node<<1|1, mid+1, r, x, y, val+st[node].sal);
}

long long query(int node, int l, int r, int i){
    pushdown(node, l, r);
    if(l == r) return st[node].val;
    int mid = (l+r)>>1;
    if(i <= mid) return st[node].val + query(node<<1, l, mid, i);
    else return st[node].val + query(node<<1|1, mid+1, r, i);
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    build(1,1,n);

    
    while(q--){
        int t; cin >> t;

        if(t == 1){
            int l, r, x; cin >> l >> r >> x;
            update(1,1,n,l,r,x);
        }
        else{
            int l, r; cin >> l >> r;
            upd(1,1,n,l,r,0);
        }
    }

    for(int i = 1; i <= n; i++) cout << query(1,1,n,i) << " ";
    

    
    


}