#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n;

vector<pair<int,bool>> adj[MAXN];

set<int> dfs(int node, int par, bool bad){
    set<int> res;
    for(auto [child, bad] : adj[node]){
        if(child == par) continue;
        set<int> tmp = dfs(child, node, bad);
        if(res.size() < tmp.size()) res.swap(tmp);
        for(int i : tmp) res.insert(i);
    }


    if(res.empty() && bad) res.insert(node);


    return res;
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y, c == 2});
        adj[y].push_back({x, c == 2});
    }

    set<int> ans = dfs(1, -1, 0);

    cout << ans.size() << "\n";
    for(int i : ans) cout << i << " ";
    cout << "\n";


}