#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 5e5+5;
const long long B = 911382629;
const long long MOD = 1e18 + 3;

int n, sz[MAXN], dp[MAXN], k;

long long h[MAXN];

map<long long, int> hsh,freq, tmp;

set<int> ans;

vector<int> adj[MAXN];

/*
tree isomorphism

everything except for last case is easy

all trees we look at must have the same sum of subtree sizes

n - d == sum of subtree sizes

now selecting green nodes is irrelevant as we can just choose which ones we want

when there are few proper nodes, there are many queries
thus the opposite is also true
when there are many proper nodes they have small subtree sizes
*/

void init(int node, int par){
    h[node] = 1;

    vector<int> c;
    for(int child : adj[node]){
        if(child == par) continue;
        init(child, node);
        sz[node] += sz[child];
        dp[node] += dp[child];
        c.push_back(h[child]);
    }

    sz[node]++;
    dp[node] += sz[node];

    sort(c.begin(), c.end());

    for(int child : c) h[node] = h[node] ^ (((h[node] * B) % MOD + child) % MOD) % MOD;     
    freq[h[node]]++;
}


//i will be part of d other subtrees
void sub(int node, int par, int d){
    tmp[h[node]] += d;

    for(int child : adj[node]){
        if(child == par) continue;
        sub(child, node, d+1);
    }
}

void dfs(int node, int par){
    if(dp[node] == n-k){
        tmp.clear();
        sub(node, par, 1);
        bool flag = 1;
        for(auto [x,y] : tmp) flag &= (freq.find(x) != freq.end() && freq[x] >= y);
        if(flag) ans.insert(h[node]);
    }

    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node);
    }
}

int main(){
    cin >> n >> k;

    for(int i = 1; i < n; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    init(1,-1);

    dfs(1,-1);

    cout << ans.size() << "\n";
}