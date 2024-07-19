#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, sz[MAXN], in[MAXN], out[MAXN], t;

bool marked[MAXN];

vector<int> adj[MAXN];

//always query the centroid of the thing
//after we move to the subtree that contains the query answer


int query(int x){
    cout << x << "\n";
    int y; cin >> y;
    return y;
}

void init(int node, int par){
    sz[node] = 1;

    for(int child : adj[node]){
        if(marked[child] || child == par) continue;
        init(child, node);
        sz[node] += sz[child];
    }
}

int centroid(int node, int par, int sub){
    for(int child : adj[node]){
        if(marked[child] || par == child) continue;

        if(sz[child] * 2 > sub) return centroid(child, node, sub);
    }

    return node;
}

void times(int node, int par){
    in[node] = ++t;
    for(int child : adj[node]){
        if(marked[child] || child == par) continue;
        times(child, node);
    }
    out[node] = t;
}

void build(int node, int par){
    init(node, par);

    int rt = centroid(node, par, sz[node]);
    marked[rt] = 1;

    int c = query(rt);
    t = 0;
    times(rt, rt);

    for(int child : adj[rt]){
        if(marked[child]) continue;
        if(in[c] >= in[child] && in[c] <= out[child]) build(child, rt);
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    build(1,-1);
}