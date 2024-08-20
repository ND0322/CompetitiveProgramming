#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,q;

struct Node{
    int pref, suf, sm; 
} st[MAXN<<2];

Node dummy;

Node comb(Node a, Node b){
    Node ans;
    ans.sm = a.sm + b.sm;
    ans.pref = min(a.pref, a.sm + b.pref);
    ans.suf = max(b.suf, a.suf + b.sm);
    return ans;
}

void build(int node, int l, int r){
    if(l == r){
        char c; cin >> c;

        if(c == '(') st[node].sm = 1;
        else st[node].sm = -1;

        st[node].pref = min(0, st[node].sm);
        st[node].suf = max(0, st[node].sm);
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = comb(st[node<<1], st[node<<1|1]);
    
}

Node query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return dummy;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return comb(query(node<<1,l,mid,x,y), query(node<<1|1,mid+1,r,x,y));
}

int main(){
    cin >> n >> q;

    dummy.pref = 1e9;
    dummy.suf = -1e9;
    dummy.sm = 0;

    build(1,1,n);

    while(q--){
        int l, r; cin >> l >> r;

        Node ans = query(1,1, n,l,r);

        //cout << ans.pref << " " << ans.suf << " " << ans.sm << "\n";

        if(ans.pref < 0 && ans.suf > 0){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

    }
}