#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

int n, sz[MAXN];
vector<int> adj[MAXN];



//must end at a centroid intuitively 
//root at centroid and process subtrees

void init(int node, int par){
    sz[node] = 1;

    for(int child : adj[node]){
        if(child == par) continue;
        init(child, node);
        sz[node] += sz[child];
    }
}

int centroid(int node, int par, int sub){
    for(int child : adj[node]){
        if(child == par) continue;
        if(sz[child] * 2 > sub) return centroid(child, node, sub);
    }
    return node;
}

bool dfs(int node, int par){
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int child : adj[node]){
        if(child == par) continue;
        if(!dfs(child, node)) return 0;
        pq.push(sz[child]);
    }

    int cur = 1;

    while(pq.size()){

        if(pq.top() > cur) return 0;
        cur += pq.top();
        pq.pop();
    }

    return 1;
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    init(1,-1);

    int rt = centroid(1,-1,n);

    init(rt,-1);


    cout << (dfs(rt, -1) ? "YES\n" : "NO\n");



}