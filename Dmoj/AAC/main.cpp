#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, q, heavy[MAXN], sz[MAXN], top[MAXN], pos[MAXN], depth[MAXN], parent[MAXN], t;

vector<int> adj[MAXN];

struct Node{
    int lz, sm;
} st[MAXN<<2];

void pushdown(int node, int l, int r){
    st[node<<1].lz += st[node].lz;
    st[node<<1|1].lz += st[node].lz;

    int mid = (l+r)>>1;
    if(l != r){
        st[node<<1].sm += st[node].lz * (mid - l+1);
        st[node<<1|1].sm += st[node].lz * (r-mid);
    }

    st[node].lz = 0;
}

void update(int node, int l, int r, int x, int y, int v){
    
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].lz += v;
        st[node].sm += (r-l+1) * v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node,l,r);
    update(node<<1, l, mid, x, y, v);
    update(node<<1|1,mid+1,r,x,y,v);
    st[node].sm = st[node<<1].sm + st[node<<1|1].sm;
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sm;

    int mid = (l+r)>>1;
    pushdown(node,l,r);
    return query(node<<1, l, mid, x,y) + query(node<<1|1,mid+1,r,x,y);
}

void init(int node){
    sz[node] = 1;
    pair<int,int> big = {0,0};
    for(int child : adj[node]){
        if(child == parent[node]) continue;
        parent[child] = node;
        depth[child] = depth[node]+1;
        init(child);
        sz[node] += sz[child];
        big = max(big, {sz[child], child});
    }
    heavy[node] = big.second;
}

void hld(int node, int rt){
    pos[node] = ++t;
    top[node] = rt;
    if(heavy[node]){
        hld(heavy[node], rt);
        for(int child : adj[node]){
            if(child == parent[node] || child == heavy[node]) continue;
            hld(child, child);
        }
    }
}

void updatepath(int x, int y, int v){
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x,y);
        update(1,1,n, pos[top[x]], pos[x], v);
        x= parent[top[x]];
    }

    if(depth[x] > depth[y]) swap(x,y);
    update(1,1,n,pos[x], pos[y], v);
}

int querypath(int x, int y){
    int ans = 0;
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x,y);
        ans += query(1,1,n, pos[top[x]], pos[x]);
        x = parent[top[x]];
    }
    if(depth[x] > depth[y]) swap(x,y);
    ans += query(1,1,n, pos[x], pos[y]);
    return ans;
}
int main(){
    cin >> n >> q;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    init(1);
    hld(1,1);

    while(q--){
        int k; cin >> k;

        vector<int> nodes(k);
        int ans = 0;
        for(int i = 0; i < k; i++){
            cin >> nodes[i];
            ans += depth[nodes[i]];
            updatepath(1, nodes[i], 1);
        }

        int best = 1e9;

        for(int i = 0; i < k; i++) best = min(best, querypath(1, nodes[i]));
        cout << ans-best << "\n";
        cout << ans << " " << best << "\n";
        for(int i = 0; i < k; i++) updatepath(1,nodes[i], -1);
    }
}