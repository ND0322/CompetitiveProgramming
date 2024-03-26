#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, q, start[MAXN], leave[MAXN], t;

long long st[MAXN<<1], a[MAXN];

vector<int> adj[MAXN];

void dfs(int node, int par){
    start[node] = t++;

    for(int child:adj[node]){
        if(child == par) continue;
        dfs(child,node);
    }

    leave[node] = t;
}

void build(){
    for(int i = n-1; i > 0; i--) st[i] = st[i>>1] + st[i>>1|1];
}

void update(int i, int x){
    for(st[i+=n] = x; i > 1; i>>=1) st[i>>1] = st[i] + st[i^1];
}

long long query(int l, int r){
    long long ans = 0;

    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) ans += st[l++];
        if(r&1) ans += st[--r];
    }

    return ans;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);

    for(int i = 1; i <= n; i++) update(start[i], a[i]);

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int i; long long x; cin >> i >> x;

            update(start[i], x);
        }
        else{
            int i; cin >> i;

            cout << query(start[i], leave[i]) << "\n";
        }
    }
}

