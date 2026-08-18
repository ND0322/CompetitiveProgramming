#include <bits/stdc++.h>
#include <iostream>

//gready simulation

using namespace std;

const int MAXN = 2e5+5;

int n, m, par[MAXN];




set<int> adj[MAXN];


void find(int x){
    while(x != par[x]){
        par[x] = par[par[x]]
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
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) par[i]= i;

    queue<int> q;

    for(int )




}