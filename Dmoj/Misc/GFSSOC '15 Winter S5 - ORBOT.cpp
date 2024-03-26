#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

#define int long long

int n,q, cnt, a[MAXN];


struct Node{
    int pref, suf, ans,ext;
} st[MAXN<<2];

//seg tree keep prefix or, ans, suffix or
//if its a negative thing in the build we just set both to 0 otherwise to a[i]

Node comb(Node a, Node b){
    Node res;

    res.ans = max({a.ans, b.ans, b.pref | a.suf});
    res.pref = a.pref;
    res.suf = b.suf;
    res.ext = a.ext | b.ext;

    return res;
}

void build(int node, int l, int r){
    if(l == r){
        cin >> st[node].ans;
        st[node].ext = st[node].ans;
        a[l] = st[node].ans;

        if(st[node].ans < 0){
            st[node].pref = 0;
            st[node].suf = 0;
            cnt++;
            
        }
        else{
            st[node].pref = st[node].ans;
            st[node].suf = st[node].ans;
        }

        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1, mid+1,r);
    st[node] = comb(st[node<<1], st[node<<1|1]);
}

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node].ans = x;
        st[node].ext = x;

        if(x < 0){
            st[node].pref = 0;
            st[node].suf = 0;
        }
        else {
            
            st[node].pref = x;
            st[node].suf = x;
        }

        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1,mid+1,r,i,x);
    st[node] = comb(st[node<<1], st[node<<1|1]);

}

/*
Node query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return Node({0,0,0});
    if(x <= l && r >= )
}
*/

int32_t main(){
    cin >> n >> q;


    build(1,1,n);

    while(q--){
        int i,x; cin >> i >> x;

        if(a[i] < 0)cnt--; 
        if(x < 0) cnt++;

        a[i] = x;

        update(1,1,n,i,x);

        if(cnt == n || !cnt) cout << st[1].ext << "\n";
        else cout << st[1].ans << "\n";

    }
}
