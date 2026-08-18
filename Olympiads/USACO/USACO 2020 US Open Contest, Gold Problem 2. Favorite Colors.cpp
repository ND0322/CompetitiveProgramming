#include <bits/stdc++.h>
#include <iostream>

//gready simulation

using namespace std;

const int MAXN = 2e5+5;

int n, m, par[MAXN], ans[MAXN], col[MAXN];




set<int> adj[MAXN];


int find(int x){
    while(x != par[x]){
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(adj[y].size() > adj[x].size()) swap(x,y);
    for(int i : adj[y]) adj[x].insert(find(i));
    par[y] = x;
    
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].insert(y);
    }

    for(int i = 1; i <= n; i++) par[i]= i;

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(adj[i].size() > 1)q.push(i);
    }

    while(q.size()){
        int node = q.front();

        q.pop();

        if(adj[node].size() <= 1) continue;

        int a = *adj[node].begin();

        adj[node].erase(adj[node].begin());
        int b = *adj[node].begin();
        uni(a,b);

        if(adj[find(a)].size() > 1) q.push(find(a));
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!col[find(i)]) col[find(i)] = ++cnt;
        ans[i] = col[find(i)];
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << "\n";




}