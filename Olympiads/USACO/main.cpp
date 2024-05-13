#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, q, a[MAXN], top[MAXN], pos[MAXN], sz[MAXN], par[MAXN], heavy[MAXN], depth[MAXN], t, st[MAXN<<2];

vector<int> adj[MAXN];

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1,mid+1,r,i,x);
    st[node] = st[node<<1] ^ st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return query(node<<1,l,mid,x,y) ^ query(node<<1|1,mid+1,r,x,y); 
}

void init(int node){
    sz[node] = 1;
    int big = 0;
    for(int child : adj[node]){
        if(child == par[node]) continue;
        par[child] = node;
        depth[child] = depth[node]+1;
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
    update(1,1,n,pos[node], a[node]);
    if(heavy[node]){
        hld(heavy[node], rt);
        for(int child : adj[node]){
            if(child == heavy[node] || child == par[node]) continue;
            hld(child, child);
        }
    }
}

int querypath(int x, int y){
    int ans = 0;
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x,y);
        ans ^= query(1,1,n,pos[top[x]], pos[x]);
        x = par[top[x]];
    }

    if(depth[x] > depth[y]) swap(x,y);
    ans ^= query(1,1,n,pos[x], pos[y]);
    return ans;
}

int main(){
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    init(1);
    hld(1,1);


    while(q--){
        int t; cin >> t;

        if(t == 1){
            int x,v; cin >> x >> v;
            update(1,1,n,pos[x], v);
        }
        else{
            int x,y; cin >> x >> y;
            cout << querypath(x,y) << "\n";
        }
    }
}