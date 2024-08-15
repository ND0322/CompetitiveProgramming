#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e4+5;

int n, q, c[MAXN], v[MAXN], st[MAXN<<2][105], ans[105];



void build(int node, int l, int r) {
    if(l == r) {
        for(int i = c[l]; i <= 100; i++) st[node][i] = v[l];
        return;
    }
    int mid = (l+r)>>1;
    build(node<<1, l ,mid);
    build(node<<1|1,mid+1,r);
    memset(st[node], 0, sizeof st[node]);
    for(int i = 1; i <= 100; i++){
        for(int j = 0; j <= i; j++) st[node][i] = max(st[node][i], st[node<<1][j] + st[node<<1|1][i - j]);
    }
}

void query(int node, int l, int r, int x, int y) {
    if(l == x && y == r) {
        for(int i = 100; i >= 0; i--){
            for(int j = 0; j < i; j++) ans[i] = max(ans[i], ans[j] + st[node][i - j]);
        }
        return;
    }
    int mid = (l+r)>>1;
    if(y <= mid) query(node<<1, l, mid, x, y);
    else if(x > mid) query(node<<1|1, mid + 1, r, x, y);
    else query(node<<1, l, mid, x, mid), query(node<<1|1, mid + 1, r, mid + 1, y);
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> c[i] >> v[i];

    build(1,1,n);

    cin >> q;

    int sm = 0;

    while(q--){
        int l,r,k; cin >> l >> r >> k;

        query(1,1,n,l,r);
        cout << ans[k] << "\n";
        sm += ans[k];
    }

    cout << sm << "\n";
}

