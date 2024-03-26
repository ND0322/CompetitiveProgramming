#include <bits/stdc++.h>
#include <iostream>
#include <set>



using namespace std;

typedef pair<int,int> pii;

//find all minimum vertices after removing one by one with set
//reverse this and use dsu to do size of comp

const int MAXN = 2e5+5;

int n,m,deg[MAXN], parents[MAXN], sz[MAXN];

bool vis[MAXN];

vector<int> adj[MAXN], order;

vector<long long> degrees;

set<pii> nodes;

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

    if(sz[x] < sz[y]) swap(x,y);
    parents[x] = y;
    sz[x] += sz[y];
    sz[y] = sz[x];
}

int main(){
    cin >> n >> m;

    for(int i = 1;i <= n; i++){
        parents[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        deg[x]++;
        deg[y]++;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) nodes.insert({deg[i], i});

    for(int i = 0; i < n; i++){
        int node = (*nodes.begin()).second;
        int d = (*nodes.begin()).first;

        order.push_back(node);
        degrees.push_back(d);

        vis[node] = 1;

        for(int child : adj[node]){
            if(!vis[child]){
                nodes.erase(make_pair(deg[child], child));
                deg[child]--;
                nodes.insert({deg[child], child});
            }
        }

        nodes.erase(make_pair(d,node));
    }

    fill(vis,vis+n+1,0);
    reverse(order.begin(), order.end());
    reverse(degrees.begin(), degrees.end());

    int mx = 1;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        int node = order[i];
        vis[node] = 1;

        for(int child : adj[node]){
            if(vis[child]){
                uni(node, child);
                mx = max(mx, sz[find(node)]);
            }
        }

        ans = max(ans, mx * degrees[i]);
    }

    cout << ans << "\n";
}