#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, q, st[MAXN<<2];

void build(int node, int l, int r, bool t){
    if(l == r){
        cin >> st[node];
        return;
    }


    int mid = (l+r)>>1;
    build(node<<1, l, mid, t^1);
    build(node<<1|1, mid+1,r, t^1);
    if(t) st[node] = st[node<<1] | st[node<<1|1];
    else st[node] = st[node<<1] ^ st[node<<1|1];
}

void update(int node, int l, int r, int i, int x, bool t){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i,x,t^1);
    else update(node<<1|1,mid+1,r,i,x,t^1);
    if(t) st[node] = st[node<<1] | st[node<<1|1];
    else st[node] = st[node<<1] ^ st[node<<1|1];
}

int main(){
    cin >> n >> q;

    bool s = n&1;
    n = 1<<n;

    build(1,1,n, s);

    while(q--){
        int i, x; cin >> i >> x;

        update(1,1,n,i,x,s);
        cout << st[1] << "\n";
    }
}