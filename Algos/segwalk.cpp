#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, st[MAXN<<2],q;

//solving
//https://dmoj.ca/problem/bsfast

void build(int node, int l, int r){
    if(l == r){
        cin >> st[node];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l,mid);
    build(node<<1|1, mid+1, r);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

void update(int node, int l, int r, int i, int val){
    if(l == r){
        st[node] = val;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, val);
    else update(node<<1|1, mid+1,r,i,val);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y, int k){
    if(l == x && r == y && st[node] >= k) return -1;
    if(l == r) return l;

    int mid = (l+r)>>1;
    if(y <= mid) return query(node<<1, l, mid, x, y, k);
    else if(x > mid) return query(node<<1|1, mid+1, r, x, y, k);
    else{
        int res = query(node<<1, l , mid,x, mid, k);
        return (res != -1 ? res :  query(node<<1|1, mid+1 , r,mid+1, y, k));
    } 
}





int main(){
   cin.tie(NULL) -> ios_base::sync_with_stdio(0);

    cin >> n >> q;

    
    build(1, 1, n);

    int last = 0;

    while(q--){
        int t; cin >> t;

        if(t == 2){
            int l,r,k; cin >> l >> r >> k;
            
            l ^= last, r ^= last, k ^= last;
            last = query(1, 1, n, l, r, k);
            cout << last << "\n";
        }
        else{
            int i,x; cin >> i >> x;

            i ^= last, x ^= last;

            update(1, 1, n, i, x);
        }
    }

   

}