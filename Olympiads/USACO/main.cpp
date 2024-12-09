#include <bits/stdc++.h>
#include <iostream>
 
using namespace std;
 
const int MAXN = 2e5+5;
 
//https://cses.fi/problemset/task/2134/
 
 
int n,q, a[MAXN], sz[MAXN], par[MAXN], depth[MAXN], heavy[MAXN], top[MAXN], pos[MAXN], t, ans[MAXN];

vector<int> col[MAXN];
vector<pair<pair<int,int>, int>> queries[MAXN];
 
vector<int> adj[MAXN];
 
struct Node{
    long long mn, mx, sum, lzAdd, lzSet;
    Node(){};
} st[MAXN<<2];
 
void pushdown(int node, int l, int r, int mid){
    if(st[node].lzSet){
        st[node<<1].lzSet = st[node<<1|1].lzSet = st[node].lzSet;
        st[node<<1].lzAdd = st[node<<1|1].lzAdd = 0;
        st[node<<1].mn = st[node<<1|1].mn = st[node].lzSet;
        st[node<<1].mx = st[node<<1|1].mx = st[node].lzSet;
 
        if(l != r){
            st[node<<1].sum = st[node].lzSet * (mid-l+1);
            st[node<<1|1].sum = st[node].lzSet * (r-mid);
        }
        
    }
 
    if(st[node].lzAdd){
        st[node<<1].lzAdd += st[node].lzAdd;
        st[node<<1|1].lzAdd += st[node].lzAdd;
        st[node<<1].mn += st[node].lzAdd;
        st[node<<1|1].mn += st[node].lzAdd;
        st[node<<1].mx += st[node].lzAdd;
        st[node<<1|1].mx += st[node].lzAdd;
        if(l != r){
            st[node<<1].sum += st[node].lzAdd * (mid-l+1);
            st[node<<1|1].sum += st[node].lzAdd * (r-mid);
        }
    }
 
    st[node].lzAdd = st[node].lzSet = 0;
}
 
void build(int node, int l, int r){
    if(l == r){
        st[node].mn = a[l];
        st[node].sum = a[l];
        st[node].mx = a[l];
        return;
    }
 
    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1,mid+1,r);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}
 
void add(int node, int l, int r, int x, int y, long long v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn += v;
        st[node].mx += v;
        st[node].sum += (r-l+1)*v;
        st[node].lzAdd += v;
        return;
    }
 
    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    add(node<<1, l, mid, x, y, v);
    add(node<<1|1, mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}
 
void update(int node, int l, int r, int x, int y, long long v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn = v;
        st[node].mx = v;
        st[node].sum = (r-l+1)*v;
        st[node].lzAdd = 0;
        st[node].lzSet = v;
        return;
    }
 
    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    update(node<<1,l,mid,x,y,v);
    update(node<<1|1,mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}
 
long long qmn(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e18;
    if(x <= l && y >= r) return st[node].mn;
    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    return min(qmn(node<<1, l, mid, x,y), qmn(node<<1|1,mid+1,r,x,y));
}
 
long long qmx(int node, int l, int r, int x, int y){
    if(x > r || y < l) return -1e18;
    if(x <= l && y >= r) return st[node].mx;
    int mid = (l+r)>>1;
    pushdown(node,l, r, mid);
    return max(qmx(node<<1,l,mid,x,y), qmx(node<<1|1,mid+1,r,x,y));
}
 
long long qsm(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sum;
    int mid = (l+r)>>1;
    pushdown(node,l,r,mid);
    return qsm(node<<1,l,mid,x,y) + qsm(node<<1|1,mid+1,r,x,y);
}
 
 
void init(int node){
    sz[node] = 1;
    int big = 0;
    for(int child : adj[node]){
        if(child == par[node]) continue;
        depth[child] = depth[node]+1;
        par[child] = node;
        init(child);
        sz[node] += sz[child];
        if(sz[child] > big){
            big = sz[child];
            heavy[node] = child;
        }
    }
}
 
void hld(int node, int rt){
    pos[node] = ++t;
    top[node] = rt;
    if(heavy[node]){
        hld(heavy[node], rt);
        for(int child : adj[node]){
            if(child == par[node] || child == heavy[node]) continue;
            hld(child, child);
        }
    }
}
 
long long querypath(int x, int y){
    long long ans = 0;
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x,y);
        //replace max with operator and change segtree query
        ans = ans + qsm(1,1,n,pos[top[x]], pos[x]);
        x = par[top[x]];
    }
    if(depth[x] > depth[y]) swap(x,y);
    ans = ans + qsm(1,1,n,pos[x], pos[y]);
    return ans;
}
 
void updatepath(int x, int y, long long v){
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x,y);
        update(1,1,n,pos[top[x]], pos[x], v);
        x = par[top[x]];
    }
    if(depth[x] > depth[y]) swap(x,y);
    update(1,1,n,pos[x], pos[y], v);
}
 
int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> n >> q;
 
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        col[x].push_back(i);
    }
 
    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    init(1);
    hld(1,1);

    for(int i = 1; i <= q; i++){
        int x,y,c; cin >> x >> y >> c;
        queries[c].push_back({{x,y}, i});
    }

    for(int i = 1; i <= n; i++){
        for(int j : col[i]) updatepath(j,j,1);
        for(auto qu : queries[i]) ans[qu.second] = (bool)querypath(qu.first.first, qu.first.second);
        for(int j : col[i]) updatepath(j,j,0);
    }

    for(int i = 1; i <= q; i++) cout << ans[i];
    cout << "\n";

 
    
}