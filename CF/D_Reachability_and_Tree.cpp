#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//bipartiteness?
//any node will contribute its depth to a full chain 
//include exactly one chain of 2

const int MAXN = 2e5+5;

int n, rt, l, r;
vector<int> adj[MAXN];
vector<pair<int,int>> ans;

void dfs1(int node, int par){
    pair<int,int> p = {-1,-1};
    int cnt = 0;

    for(int child : adj[node]){
        if(p.first == -1) p.first = child;
        else p.second = child;
        cnt++;
    }

    if(cnt == 2){
        rt = node;
        l = p.first;
        r = p.second;
        return;
    }

    for(int child : adj[node]){
        if(child == par) continue;
        dfs1(child, node);
    }
}

void dfs(int node, int par, bool col){
    if(node == rt){
        dfs(l, node, 0);
        ans.push_back({l, node});
        //0 for to parent

        dfs(r, node, 1);
        ans.push_back({node, r});

        for(int child : adj[node]){
            if(child == par || child == l || child == r) continue;
            dfs(child, node, 0);
            ans.push_back({child, node});
        }

        return;
    }

    for(int child : adj[node]){
        if(child == par) continue;
        
        //if parent was towards me
        if(col) ans.push_back({child, node});
        else ans.push_back({node, child});

        dfs(child, node, !col);
    }


}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) adj[i].clear();
        ans.clear();
        rt = 0;
        l = 0;
        r = 0;

        for(int i = 0; i < n-1; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }


        dfs1(1, -1);

        if(!rt){
            cout << "NO\n";
            continue;
        }


        dfs(rt, -1, 0);

        cout << "YES\n";

        for(auto [x,y] : ans) cout << x << " " << y << "\n";




    }
}