#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,m, f, depth[MAXN];

bool gym[MAXN];

bool a[MAXN], b[MAXN];

vector<int> adj[MAXN];

void dfs(int node, int par){
    a[node] = gym[node];
    b[node] = gym[node] | (node == f);
    
    for(int child : adj[node]){
        if(child == par) continue;
        depth[child] = depth[node]+1;
        dfs(child, node);
        a[node] |= a[child];
        b[node] |= b[child];
    }
}

int main(){
    cin >> n >> m >> f;

    for(int i = 0; i < m; i++){
        int x; cin >> x;

        gym[x] = 1;
    }

    for(int i = 0; i < n-1; i ++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);

    long long ans = 0;

    int mx = 0;
    for(int i = 2; i <= n; i++){
       ans += 2*a[i];

       if(gym[i]) mx = max(mx, depth[i]);
    }

    ans-=mx;

    long long ans2 = 0;

    for(int i = 2; i <= n; i++) ans2 += b[i];

    cout << min(ans,ans2) << "\n";
    




}