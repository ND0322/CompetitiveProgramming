#include <bits/stdc++.h>
#include <iostream>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

using namespace std;

const int MAXN = 5e5+5;


int n, m, q;

struct Node{
    int pref, suf, val, sm, lz;
} dummy;
vector<Node> st[MAXN];

/*
keep a seg tree for each column and row
basically rip that one coci question but add lazy set  
remember to use the correct n for seg tree either n or m
query the range and also query the left and right prefix suffixes 
*/

void pushdown(int node, int l, int r, int c){
    if(st[c][node].lz == -1) return;

    int mid = (l+r)>>1;
    st[c][node<<1].lz = st[c][node].lz;
    st[c][node<<1|1].lz = st[c][node].lz;
    if(r != l){
        st[c][node<<1].pref = st[c][node].lz * (mid - l + 1);
        st[c][node<<1|1].pref = st[c][node].lz * (r-mid);
        st[c][node<<1].suf = st[c][node].lz * (mid - l + 1);
        st[c][node<<1|1].suf = st[c][node].lz * (r-mid);
        st[c][node<<1].val = st[c][node].lz * (mid - l + 1);
        st[c][node<<1|1].val = st[c][node].lz * (r-mid);
        st[c][node<<1].sm = st[c][node].lz * (mid - l + 1);
        st[c][node<<1|1].sm = st[c][node].lz * (r-mid);
    }
    
    st[c][node].lz = -1;
}

Node comb(Node a, Node b){
    Node ans;

    ans.pref = (a.pref == a.val) * b.val + a.pref;
    ans.suf = (b.suf == b.val) * a.val + b.suf;
    ans.val = max({a.val, b.val, a.suf + b.pref});
    ans.sm = a.sm + b.sm;
    return ans;
}

void update(int node, int l, int r, int x, int y, int v, int c){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[c][node].pref = v * (r-l+1);
        st[c][node].suf = v * (r-l+1);
        st[c][node].val = v * (r-l+1);
        st[c][node].sm = v * (r-l+1);
        st[c][node].lz = v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, c);
    update(node<<1, l, mid, x, y, v, c);
    update(node<<1|1,mid+1,r,x,y,v,c);
    st[c][node] = comb(st[c][node<<1], st[c][node<<1|1]);
    st[c][node].lz = -1;
}

Node query(int node, int l, int r, int x, int y, int c){
    if(x > r || y < l) return dummy;
    if(x <= l && y >= r) return st[c][node];
    int mid = (l+r)>>1;
    pushdown(node,l,r,c);
    return comb(query(node<<1,l,mid, x, y, c), query(node<<1|1,mid+1,r,x,y,c));
}

int bsearch(int i, int pos){
    int lo = 1;
    int hi = i;

    int l = 0;

    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(query(1,1,(pos <= n ? n : m), mid, i, pos).sm == (i-mid+1)){
            l = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    int r = 0;

    lo = i;
    hi = (pos <= n ? n : m);

    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(query(1,1,(pos <= n ? n : m), i, mid, pos).sm == (mid - i + 1)){
            r = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    return r-l+1;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin >> n >> m >> q;

    
    dummy.pref = 0;
    dummy.suf = 0;
    dummy.val = 0;
    dummy.sm = 0;
    dummy.lz = -1;

    //add rows
    for(int i = 0; i <= n; i++) st[i] = vector<Node> ((m+1)<<2, dummy);
    for(int i = n+1; i <= n+m; i++) st[i] = vector<Node> ((n+1)<<2, dummy);

    while(q--){
        int t, x,y,z; cin >> t >> x >> y >> z;

        if(t == 1 || t == 2){
            //update rows
            for(int i = x; i <= x+z-1; i++) update(1,1, m, y,y+z-1, !(t-1), i);
            for(int i = n+y; i <= n + y + z-1; i++) update(1,1,n, x, x+z-1, !(t-1), i);
        }
        else{
            int ans = 0;
            for(int i = x; i <= x+z-1; i++){
                ans = max(ans, query(1,1,m,y, y+z-1, i).val);   
                ans = max(ans, bsearch(y,i));
                ans = max(ans, bsearch(y+z-1,i));
            }
            for(int i = n+y; i <= n + y + z-1; i++){
                ans = max(ans, query(1,1,n, x, x+z-1, i).val);
                ans = max(ans, bsearch(x,i));
                ans = max(ans, bsearch(x+z-1,i));
            }
        
            cout << ans << "\n";
        }
    }
}

