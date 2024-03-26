#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,q,st[MAXN<<2],a[MAXN];

void build(int l = 1, int r = n, int node = 1){
    if(l == r) st[node] = a[l];
    else{
        int mid = (l+r)>>1;

        build(l,mid,node<<1);
        build(mid+1,r,node<<1|1);
        st[node] = max(st[node<<1],st[node<<1|1]);
    }
}

void query(int val,int l = 1, int r = n, int node = 1){
    if(l == r){
        cout << l << " ";
        st[node] -= val;
    }
    else{
        int mid = (l+r)>>1;

        if(st[node<<1] >= val) query(val,l,mid,node<<1);
        else query(val,mid+1,r,node<<1|1);

        st[node] = max(st[node<<1],st[node<<1|1]);
    }
}

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    build();

    while(q--){
        int x; cin >> x;

        if(st[1] < x) cout << "0 ";
        else query(x);
    }


}