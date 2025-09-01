#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;


/*
small to large for the bottom part and segtree bsearch for top part
coord compress
*/

int n, st[MAXN<<2], a[MAXN], ans[MAXN];

map<int,int> coord, rev;

vector<pair<int,int>> adj[MAXN];

map<int,int> mp[MAXN];
set<int> good[MAXN];

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node]+=x;
        return; 
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;

    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return query(node<<1, l, mid, x,y) + query(node<<1|1, mid+1, r, x, y);
}

void dfs(int node, int par, int id){

    int mx = 0;

    for(auto [child, cid] : adj[node]){
        if(child == par) continue;

        dfs(child, node, cid);

        if(mp[node].size() < mp[child].size()) swap(mp[node], mp[child]);

        for(auto i : mp[child]){
            mp[node][i.first] += i.second;
            if(mp[node][i.first] >= 2) mx = max(mx, i.first);
        }
    }

    mp[node][a[node]]++;
}


int main(){
    cin >> n;

    for(int i = 1; i <= n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }

    for(int i = 1; i <= n; i++) cin >> a[i];


    vector<int> s;

    for(int i = 1; i <= n; i++) s.push_back(a[i]);

    s.resize(distance(s.begin(), unique(s.begin(), s.end())));


    for(int i = 0; i < s.size(); i++){
        coord[s[i]] = i+1;
        rev[i+1] = s[i];
    }

    for(int i = 1; i <= n; i++) update(1,1,n, coord[a[i]], 1);






}