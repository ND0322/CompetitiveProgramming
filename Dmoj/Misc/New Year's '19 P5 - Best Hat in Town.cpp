#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 2e5+5;

int n, a[MAXN], low[MAXN<<2], disc[MAXN<<2], t, comp[MAXN<<2], sz[MAXN<<2], cnt;

pair<int,int> l[MAXN];


vector<int> adj[MAXN<<2];


void update(int node, int l, int r, int x, int y, int u){
    if(x > r || y < l) return;
    if(l <= x && y >= r){
        adj[node+n].push_back(u);
        return;
    }

    int mid = (l+r)>>1;
    update(node<<1, l, mid, x, y, u);
    update(node<<1|1, mid+1,r,x,y,u);
}

void init(int node, int l, int r, int u){
    if(u < l || u > r) return;
    if(l <= u && y >= u){
        adj[u].push_back(node+n);
        return;
    }

    int mid = (l+r)>>1;

    init(node<<1,l,mid,u);
    init(node<<1|1,mid+1,r,u);
}


int main(){
    
}