#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, psa[MAXN], st[MAXN<<2], a[MAXN];

//prefix max

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] += x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i,x);
    else update(node<<1|1,mid+1,r,i,x);
    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return query(node<<1,l,mid, x, y) + query(node<<1|1,mid+1,r,x,y);
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
    }

    int q; cin >> q;

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int i,x; cin >> i >> x;
            update(1,1,n,i,x);
            //cout << i << " " << query(1,1,n,i,i) << "\n";
        }
        else{
            int i; cin >> i;
            if(i == 1){
                cout << min(a[i], query(1,1,n,i,i)) << "\n";
                continue;
            }
            cout << min(max(0, query(1,1,n,1,i-1) - psa[i-1]) + query(1,1,n,i,i), a[i]) << "\n";
        }
    }


}