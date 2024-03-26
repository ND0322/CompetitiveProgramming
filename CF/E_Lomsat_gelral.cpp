#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN];

long long ans[MAXN];

vector<int> adj[MAXN];
set<int> s[MAXN];

//if a color is not dominating 

void dfs(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;

        dfs(child, node);
        if(s[child].size() > s[node].size()) swap(s[node], s[child]);
        for(int i : s[child]) s[node].insert(i);
    }
    s[node].insert(a[node]);
    for(int i : s[node]) ans[node] += i;
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    
}

