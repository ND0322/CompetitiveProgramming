#include <bits/stdc++.h>
#include <iostream>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
 
using namespace std;
 
const int MAXN = 2e5+5;
const int MAXD = 19; 
const int MOD = 998244353;

#define int long long
 
//https://cses.fi/problemset/task/2134/
 
 
int n,q, sz[MAXN], par[MAXN], depth[MAXN], heavy[MAXN], top[MAXN], pos[MAXN], t, deg[MAXN], st[MAXN<<2], jmp[MAXN][MAXD];
 
vector<int> adj[MAXN];

int qpow(int a, int b){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % MOD;
        b /= 2;
        a = (a*a) % MOD;
    }
    return ans;
}
 
void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = (st[node<<1] * st[node<<1|1]) % MOD;
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return (query(node<<1,l,mid, x, y) * query(node<<1|1,mid+1,r,x,y)) % MOD;
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
    update(1,1,n,pos[node], max(deg[node]-1,1LL));
    if(heavy[node]){
        hld(heavy[node], rt);
        for(int child : adj[node]){
            if(child == par[node] || child == heavy[node]) continue;
            hld(child, child);
        }
    }
}
 
long long querypath(int x, int y){
    long long ans = 1;
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x,y);
        //replace max with operator and change segtree query
        ans = (ans * query(1,1,n,pos[top[x]], pos[x])) % MOD;
        x = par[top[x]];
    }
    if(depth[x] > depth[y]) swap(x,y);
    ans = (ans * query(1,1,n,pos[x], pos[y])) % MOD;
    return ans;
}






 
int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

 
    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);

        deg[x]++;
        deg[y]++;
    }

 
    init(1);
    hld(1,1);
 
    
 
    while(q--){
        int x,y; cin >> x >> y;

        if(par[y] == x){
            cout << deg[x] << "\n";
            continue;
        }
        if(par[x] == y){
            cout << deg[x] << "\n";
            continue;
        }

        if(depth[x] < depth[y]) cout << (((querypath(x,par[y]) * qpow(max(deg[x]-1, 1LL), MOD-2)) % MOD) * (deg[x])) % MOD << "\n";
        else cout << (((querypath(par[x], y) * deg[x]) % MOD) * qpow(max(deg[y] - 1, 1LL), MOD-2)) % MOD << "\n";

        
    }
}