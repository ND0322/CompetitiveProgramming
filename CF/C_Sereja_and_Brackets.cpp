#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, q;

string s;

struct Node{
    int ans, l,r;
} st[MAXN<<2];

Node bad = {0,0,0};

//add the answers and form new brackets with the l of the l and r of the r
Node comb(Node a, Node b){
    Node ans;

    ans.ans = (a.ans+b.ans+min(a.l,b.r));
    ans.l = (a.l + b.l - min(a.l,b.r));
    ans.r = (a.r + b.r - min(a.l,b.r));
    return ans;
}

void build(int node, int l, int r){
    if(l == r){
        
        char c = s[l-1];
        st[node].ans = 0;
        st[node].l = (c == '(');
        st[node].r = (c == ')');
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = comb(st[node<<1], st[node<<1|1]);
}

Node query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return bad;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return comb(query(node<<1,l,mid, x,y), query(node<<1|1,mid+1,r,x,y));
}

int main(){
    cin >> s;

    n = s.size();
    build(1,1,n);

    cin >> q;

    while(q--){
        int l,r; cin >> l >> r;

        cout << query(1,1,n,l,r).ans*2 << "\n";
    }

}