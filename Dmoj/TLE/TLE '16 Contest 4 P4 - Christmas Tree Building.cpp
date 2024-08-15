#include <bits/stdc++.h>
#include <iostream>
#include <set>

#define int long long

using namespace std;

const int MAXN = 2e5+5;

int n, m;

vector<pair<int,int>> adj[MAXN];
bool vis[MAXN];

set<pair<int,int>> s;
multiset<int> dists;

vector<pair<int,int>> path;

/*
for max, when adding components together we calculate each diameter and attach from diameter to diameter to the furthest node from 1
for min, some type of greedy?
sort component diameters from large to small and greedily attach to shortest subtree 
if we can root anywhere apparently then there needs a strat for choosing the root
*/

pair<int,int> dfs(int node, int par){
    pair<int,int> ans = {0,node};
    vis[node] = 1;
    for(auto [child, weight] : adj[node]){
        if(child == par) continue;
        pair<int,int> tmp = dfs(child, node);
        tmp.first += weight;
        ans = max(ans, tmp);
    }

    return ans;
}

bool dfs2(int node, int par, int tar, int d){

    if(node == tar){
        path.push_back({node, d});
        return 1;
    }

    for(auto [child, weight] : adj[node]){
        if(child == par) continue;

        if(dfs2(child, node, tar, d + weight)){
            path.push_back({node, d});
            return 1;
        }
    }
    return 0;
}



int32_t main(){
    cin >> n >> m;

    int t; cin >> t;

    for(int i = 1; i <= m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }


    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        s.insert(dfs(dfs(i, -1).second, -1));
    }

    if(t == 1){
        long long sm = 0;

        for(auto i : s) sm += i.first+1;
        cout << sm-1 << "\n";
        return 0;
    }

    //get the diameter path from the boi with the largest diameter 

    memset(vis, 0, sizeof(vis));
    pair<int,int> cnt = {0,0};

    for(auto balls : s){
        int rt = balls.second;
        if(vis[rt]) continue;
        int tar = dfs(rt, -1).second;
        path.clear();

        dfs2(rt,-1,tar, 0);
        reverse(path.begin(), path.end());
        int r= 0;
        for(auto [i,j] : path) r = j;

        int mn = 1e18;

        for(auto [i,j] : path){
            //r dist - i dist for right side
            //i dist for left side

            mn = min(mn, max(r - j, j));
        }

        if(cnt.first == mn) cnt.second++;
        else cnt = max(cnt, {mn, 1});
    }
    
    cout << cnt.first + (bool)(cnt.second-1) << "\n";

    

    



    


}


