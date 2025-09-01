#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

/*
Call cutie good

All good nodes at the start will remain good

All bad nodes can be done in a way such that they stay bad

Proof:

Consider the definition of good

Call si the set of colors in the ith child’s subtree

For it to be good, intersection of some si with sj is not empty

If it is bad to begin with, we can set non coloured nodes to any color in the set already

Small to large

If node u is uncoloured, color it according to the set

If size of u’s subtree != sigma v sizes than it is cutie

special logic for leaves 
*/

int n, a[MAXN], col[MAXN], ans;

vector<int> adj[MAXN];

set<int> s[MAXN];

void dfs(int node, int par){
    int sm = 0;

    for(int child : adj[node]){
        if(child == par) continue;

        dfs(child, node);

        if(s[child].size() > s[node].size()) s[node].swap(s[child]);
        int sm = s[child].size();
        for(int i : s[child]) s[node].insert(i);
    }

    if(sm != s[node].size()){
        ans += a[node];
        cout << node << "\n";
    }

    if(!col[node]) col[node] = *s[node].begin();

    s[node].insert(col[node]);
}



int main(){
    int tt; cin >> tt;

    while(tt--){
        int k; cin >> n >> k;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> col[i]; 

        for(int i = 0; i < n-1; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1, -1);

        cout << ans << "\n";

        for(int i = 1; i <= n; i++) cout << col[i] << " ";
        cout << "\n";

        for(int i = 1; i <= n; i++){
            adj[i].clear();
            s[i].clear();
        }

        ans = 0;
    }
}