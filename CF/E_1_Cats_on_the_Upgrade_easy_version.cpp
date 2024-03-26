#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, q;

struct Node{
    int cr, cl, ans;
} st[MAXN<<2];

Node comb(Node x, Node y){
    Node res;

    res.ans = x.ans + y.ans + min(x.cl, y.cr) + min(x.cr, y.cl);
    res.cl = x.cl + y.cl - min(x.cl, y.cr) - min(x.cr, y.cl);
    res.cr = x.cr + y.cr - min(x.cl, y.cr) - min(x.cr, y.cl);
    return res;
}

void build(int node, int l, int r){
    if(l == r){
        char c; cin >> c;

        st[node].ans = 0;
        st[node].cl = (c == '(');
        st[node].cr = (c == ')');
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = comb(st[node<<1], st[node<<1|1]);

}

Node query(int node, int l, int r, int x, int y){
    if(x > r || y < l){
        Node tmp;

        tmp.ans = 0;
        tmp.cl = 0;
        tmp.cr = 0;

        return tmp;
    }
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return comb(query(node<<1, l, mid, x, y), query(node<<1|1, mid+1,r,x,y));
}

/*
())(
//cnt unpaired right and left in each node

))))
*/

int main(){
    cin >> n >> q;

    build(1,1,n);

    while(q--){
        int t, l, r; cin >> t >> l >> r;

        cout << query(1,1,n,l,r).ans << "\n";
    }
}