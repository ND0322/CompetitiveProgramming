#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int M = 1e6+5;

int n, m, a[MAXN], b[MAXN], d[MAXN];

pair<int,int> points[MAXN];

struct Segtree{
    int st[MAXN<<2];

    void build(int node, int l, int r){
        if(l == r){
            st[node] = 1e9;
            return;
        }

        int mid = (l+r)>>1;
        build(node<<1, l, mid);
        build(node<<1|1, mid+1, r);
        st[node] = min(st[node<<1], st[node<<1|1]);
    }

    void update(int node, int l, int r, int i, int v){
        if( l == r){
            st[node] = v;
            return;
        }

        int mid = (l+r)>>1;
        if(i <= mid) update(node<<1, l, mid, i, v);
        else update(node<<1|1, mid+1, r, i, v);
        st[node] = min(st[node<<1], st[node<<1|1]);
    }

    int query(int node, int l, int r, int x, int y){
        if(x > r || y < l) return 1e9;
        if(x <= l && y >= r) return st[node];

        int mid = (l+r)>>1;
        return min(query(node<<1,l,mid, x, y), query(node<<1|1, mid+1, r,x ,y));
    } 
} seg[2];


/*
possible endpoints for queries are:
a, a+d, inf
b, b+d, inf

so we try all combinations and find the minimum 

eg (a, b+d)

query min of y values from 0 to a
in fact we can just check if mn < b+d and add or not add d to ans

in fact we can use two segtrees to handle all queries 

eg (a+d, b+d)

we want i + mn in column
for inf queries we just expand the query range and add however many ds 
*/

int main(){
    for(int i = 1;i <=n ;i++) cin >> points[i].first;
    
    seg[0].build(0,0,M);
    seg[1].build(0,0,M);

    map<int,int> mp;
    
    for(int i = 1; i <= n; i++){
        cin >> points[i].second;

        mp[points[i].first] = min(mp[points[i].first], points[i].second);
    }

    vector<pair<int,int>> ord;

    for(auto [x,y] : mp) ord.push_back({y,x});
    sort(ord.begin(), ord.end());

    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    for(int i = 1; i <= m; i++) cin >> d[i];

    vector<pair<int,int>> ord2;

    for(int i = 1; i <= m; i++) 

    //handle increasing order of b[i]

    for(int i =1 ; i <= m; i++){
        int ans = 1e9;

        //query 0 to a

        int mn = seg[0].query(0,0,M, 0, a[i]-1);
        
        //check what category it falls into
        if(mn < b[i]) ans = 0;
        else if(mn < b[i] + d[i]) ans = mn;
        else ans = mn + d[i];
        

        //query a to a+d

        int mn = seg[0].query(0,0, M, a[i], a[i]+d[i]-1);
    }
}