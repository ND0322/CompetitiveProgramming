#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, sz[MAXN];

bool marked[MAXN];

vector<int> adj[MAXN];

//centroid like thing

void init(int node, int par){
    sz[node] = 1;

    for(int child : adj[node]){
        if(child == par || marked[child]) continue;
        init(child, node);
        sz[node] += sz[child];
    }
}

int centroid(int node, int par, int sub){
    for(int child : adj[node]){
        if(child == par || marked[child]) continue;
        if(sz[child] * 2 > sub) return centroid(child, node, sub);
    }
    return node;
}

bool query(int node){
    cout << "? " << node << "\n";
    bool x; cin >> x;
    return x;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n-1; i++){
            int x,y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        
    }
}