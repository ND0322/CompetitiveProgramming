#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#define int long long

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

int n, m, q, low[MAXN], disc[MAXN], comp[MAXN], sz[MAXN], heavy[MAXN], top[MAXN], id[MAXN], parent[MAXN], depth[MAXN],parents[MAXN], t, cnt;

long long delta[MAXN];
bool in[MAXN];

stack<int> stk;

vector<int> adj[MAXN], adj2CC[MAXN];

/*
2CC compress to make a tree
hld on that with delta for each node
*/

void tarjan(int node, int par){
    low[node] = disc[node] = ++t;

    in[node] = 1;

    stk.push(node);

    for(int child : adj[node]){
        if(child == par){
            par = -1;
            continue;
        }

        if(!disc[child]){
            tarjan(child, node);
            low[node] = min(low[node], low[child]);
        }
        else if(in[child]) low[node] = min(low[node], disc[child]);
    }

    if(low[node] == disc[node]){
        cnt++;
        while(stk.top() != node){
            comp[stk.top()] = cnt;
            in[stk.top()] = 0;
            stk.pop();
        }
        comp[node] = cnt;
        in[node] = 0;
        stk.pop();
        
        
        
    }
}

struct Node{
    long long mn, mx, sum, lzAdd, lzSet;
    Node(){};
} st[MAXN<<2];

void build(int node, int l, int r){
    st[node].lzAdd = 0;
    st[node].lzSet = 0;
    if(l == r){
        st[node].mn = 0;
        st[node].sum = 0;
        st[node].mx = 0;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1,mid+1,r);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

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
    for(int child : adj2CC[node]){
        if(child == parent[node]) continue;
        depth[child] = depth[node]+1;
        parent[child] = node;
        init(child);
        sz[node] += sz[child];

        if(sz[child] > big){
            big = sz[child];
            heavy[node] = child;
        }
    }
}

void hld(int node, int rt){
    id[node] = ++t;
    top[node] = rt;
    if(heavy[node]){
        hld(heavy[node], rt);
        for(int child : adj2CC[node]){
            if(child == parent[node] || heavy[node] == child) continue; 
            hld(child, child);
        }
    }
}

void path(int x, int y, int v){
    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x,y);
        add(1,1,n,id[top[x]], id[x], v);
        x = parent[top[x]];
    }
    if(depth[x] > depth[y]) swap(x,y);
    add(1,1,n, id[x], id[y], v);
}

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;
    parents[x] = y;
}

int32_t main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){
        cin >> n >> m >> q;

        build(1,1,n);

        for(int i = 1; i <= n; i++){
            low[i] = 0;
            disc[i] = 0;
            comp[i] = 0;
            sz[i] = 0;
            delta[i] = 0;
            heavy[i] = 0;
            top[i] = 0;
            id[i] = 0;
            parent[i] = 0;
            depth[i] = 0;
            in[i] = 0;
            adj[i].clear();
            adj2CC[i].clear();
            t = 0;
            cnt = 0;
        }

        while(stk.size()) stk.pop();

        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for(int i = 1; i <= n; i++){
            if(!disc[i]) tarjan(i,-1);
        }

        for(int i = 1; i <= cnt; i++) parents[i] = i;

        for(int i = 1; i <= n; i++){
            for(int child : adj[i]){
                if(comp[i] == comp[child]) continue;
                adj2CC[comp[i]].push_back(comp[child]);
                adj2CC[comp[child]].push_back(comp[i]);
                uni(comp[i], comp[child]);
            }
        }

        for(int i = 0; i < cnt; i++){
            sort(adj2CC[i].begin(), adj2CC[i].end() );
            adj2CC[i].erase(unique(adj2CC[i].begin(), adj2CC[i].end() ), adj2CC[i].end());

        }
        t = 0;

        
        for(int i = 1; i <= cnt; i++){
            if(!sz[i]){
                init(i);
                hld(i,i);
            }
        }

        //cout << qsm(1,1,n,1,2) << "\n";
        long long ans = 0;

        while(q--){
            char c; cin >> c;

            if(c == 'T'){
                int x,y,v; cin >> x >> y >> v;
                
                if(find(comp[x]) == find(comp[y])) path(comp[x], comp[y], v);
            }
            else{
                int x; cin >> x;
                ans = (ans + qsm(1,1,n,id[comp[x]], id[comp[x]]) - delta[x]);
                delta[x] = qsm(1,1,n,id[comp[x]], id[comp[x]]);

            
            }
        }

        cout << ans%MOD << "\n";
    }
}