#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

#define int long long

const int MAXN = 5005;

int n;

long long a[MAXN], d[MAXN], b[MAXN];

set<pair<int,int>> subtree[MAXN];
vector<int> adj[MAXN];

long long ans = 0;

//store the difference as diff
//diff[i] = sum children i - a[i]
//we want to make diff i greater than 0 for all i
//in one operation we can increase diff[i] by 1 and simultaneously decrease a child by 1
//this can be extended by chaining multiple children
//because we do + 1 to rt and then -1 to the child
//then +1 to the child then -1 to its child 
//the middle terms cancel out and we're able to apply the operation on a node and any of the nodes in its subtree at cost d
//where d is the depth difference
//greedy after with small to large to maintain the set of nodes in subtree with b[i] > 0 and sort by their depths

void dfs(int node, int par){
    long long sm = 0;

    for(int child : adj[node]){
        if(child == par) continue;
        d[child] = d[node]+1;
        dfs(child, node);
        sm += a[child];
    }

    b[node] = ((adj[node].size() == 1 && node != 1) ? 1e9 : sm - a[node]);
}

void dfs2(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;

        dfs2(child, node);

        if(subtree[child].size() > subtree[node].size()) subtree[node].swap(subtree[child]);
        for(pair<int,int> i: subtree[child]) subtree[node].insert(i);
    }

    while(b[node] < 0){

        pair<int,int> child = *subtree[node].begin();
    
        long long val = min(-b[node], b[child.second]);
        ans += val * (child.first - d[node]);
        b[node] += val;
        b[child.second] -= val;
        
        if(b[child.second] <= 0) subtree[node].erase(subtree[node].begin());
    }
    subtree[node].insert({d[node],node});
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        fill(d+1,d+n+1,0);
        for(int i = 1; i <= n; i++){
            subtree[i].clear();
            adj[i].clear();
        }

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 2; i <= n; i++){
            int x; cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }

        

        dfs(1,-1);
        ans = 0;

        dfs2(1,-1);

        cout << ans << "\n";
    }
}