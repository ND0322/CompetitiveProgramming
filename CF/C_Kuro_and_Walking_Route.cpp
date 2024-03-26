#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, a,b, ans[2], p;

bool has[MAXN];

vector<int> adj[MAXN];

void dfs(int node, int par){
    ans[0]++;
    for(int child : adj[node]){
        if(child == par) continue;
        if(has[child]) continue;
        dfs(child, node);
    }
}

void dfs2(int node, int par){
    has[node] = (node == b);

    for(int child : adj[node]){
        if(child == par) continue;
        if(child == b) p = node;
        dfs2(child, node);
        has[node] |= has[child];
    }
}

void dfs3(int node, int par){
    ans[1]++;
    for(int child : adj[node]){
        if(child == par) continue;
        dfs3(child, node);
    }
}
int main(){
    cin >> n >> a >> b;

    for(int i = 0; i < n-1; i ++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    

    dfs2(a,-1);
    dfs(a,-1);
    dfs3(b, p);


    
    cout << (long long)n * (n-1) - (long long)ans[0] * ans[1] << "\n";
}

