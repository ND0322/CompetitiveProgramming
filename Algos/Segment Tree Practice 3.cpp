#include <bits/stdc++.h>   
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, q, sum[MAXN<<2], st[MAXN<<2];



void build(int node, int l, int r){
    if(l == r){
        cin >> sum[node];
        st[node] = sum[node];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l , mid);
    build(node<<1|1, mid+1, r);
    st[node] = max(st[node<<1], sum[node<<1] + st[node<<1|1]);
    sum[node] = sum[node<<1] + sum[node<<1|1];
}

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        sum[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1, r, i, x);
    st[node] = max(st[node<<1], sum[node<<1] + st[node<<1|1]);
    sum[node] = sum[node<<1] + sum[node<<1|1];
}

pair<int,int> query(int node, int l, int r, int x, int y){
   if(x > r || y < l) return {0,-1e9};

    if(x <= l && y >= r) return {sum[node],st[node]};

    int mid = (l+r)>>1;

    pair<int,int> fs = query(node<<1,l,mid,x,y);
    pair<int,int> sc = query(node<<1|1, mid+1, r, x, y);

    return {fs.first + sc.first, max(fs.second, fs.first + sc.second)};
    
    
}


int32_t main(){
    cin >> n >> q;

    build(1,1,n);

    while(q--){
        char t; cin >> t;

        if(t == 'U'){
            int i, x; cin >> i >> x;

            update(1,1,n,i,x);
        }

        else{
            int l, r; cin >> l >> r;

            cout << query(1,1,n,l,r).second << "\n";
        }
    }
}