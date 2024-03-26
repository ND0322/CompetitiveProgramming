#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n;

vector<int> level[MAXN], adj[MAXN];

void dfs(int node, int par, int depth){
    level[depth].push_back(node);

    for(int child : adj[node]){
        if(child != par) dfs(child,node,depth+1);
    }
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            level[i].clear();
            adj[i].clear();
        }

        for(int i = 2; i <= n; i++){
            int x; cin >> x;

            adj[x].push_back(i);
            adj[i].push_back(x);
        }

        dfs(1,-1,0);


        int ans = 0;
        int ext = 0;

        for(int i = n; i > 0; i--){
            if(level[i].empty()) continue;
            int tmp = min(ext, (int)level[i].size()-1);
            ans += tmp;
            ext -= tmp;

            ans += ((int)level[i].size() - tmp)/2;
            ext += ((int)level[i].size() - tmp) & 1;
        }

        cout << ans << "\n";
    }
}