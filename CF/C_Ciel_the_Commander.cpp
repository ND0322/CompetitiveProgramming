#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, sz[MAXN], rk[MAXN];

vector<int> adj[MAXN];
void init(int node, int par){
    sz[node] = 1;

    for(int child : adj[node]){
        if(rk[child] || child == par) continue;
        init(child, node);
        sz[node] += sz[child];
    }
}

int centroid(int node, int par, int sub){
    for(int child : adj[node]){
        if(rk[child] || child == par) continue;

        if(sz[child] * 2 > sub) return centroid(child, node, sub);
    }
    return node;
}

void dac(int node, int par, int depth){
    init(node, par);
    int rt = centroid(node, par, sz[node]);

    rk[rt] = ++depth;
    
    for(int child : adj[rt]){
        if(rk[child]) continue;
        dac(child, rt, depth);
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dac(1,-1,0);

    for(int i = 1; i <= n; i++) cout << (char)(rk[i]+'A'-1) << " ";
    cout << "\n";
}