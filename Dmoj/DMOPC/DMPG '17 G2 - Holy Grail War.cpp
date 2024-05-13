#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;


int n, q;

struct Node{
    long long ans, sum, pref, suf;
} st[MAXN<<2];

Node bad = {(long long)-1e14, (long long)-1e14, (long long)-1e14, (long long)-1e14};

Node comb(Node x, Node y){
    Node ans;
    ans.sum = x.sum + y.sum;
    ans.pref = max(x.pref, x.sum + y.pref);
    ans.suf = max(y.suf, y.sum + x.suf);
    ans.ans = max({x.ans, y.ans, x.suf + y.pref});
    return ans;
}

void build(int node, int l, int r){
    if(l == r){
        cin >> st[node].sum;

        st[node].ans = st[node].sum;
        st[node].pref = st[node].sum;
        st[node].suf = st[node].sum;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = comb(st[node<<1], st[node<<1|1]);
}

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node].sum = x;

        st[node].ans = st[node].sum;
        st[node].pref = st[node].sum;
        st[node].suf = st[node].sum;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1, r, i, x);
    st[node] = comb(st[node<<1], st[node<<1|1]);
}

Node query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return bad;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return comb(query(node<<1,l, mid, x, y), query(node<<1|1,mid+1,r, x, y));
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    build(1,1,n);
    
    

    while(q--){
        char c; cin >> c;

        if(c == 'S'){
            int i, x; cin >> i >> x;
            update(1,1,n,i,x);
            
        }
        else{
            int l,r; cin >> l >> r;
            cout << query(1,1,n,l,r).ans << "\n";
        }
    }

}