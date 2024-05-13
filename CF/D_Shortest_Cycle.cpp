#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, a[MAXN];

vector<int> has[65], adj[MAXN];
set<pair<int,int>> edges;
bool vis[MAXN];

//all bois who share a a common bit
//if one bit is shared by more than 2 than answer is 3

int bfs(int in, int out){
    memset(vis,0,sizeof(vis));

    queue<pair<int,int>> q;

    q.push({in, 0});

    while(q.size()){
        int node = q.front().first;
        int d = q.front().second;

        q.pop();

        if(node == out) return d+1;

        for(int child : adj[node]){
            if(node == in && child == out) continue;
            if(vis[child]) continue;
            vis[child] = 1;
            q.push({child, d+1});
        }
    }

    return 1e9;
}


int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];

        for(int j = 0; 1LL<<j <= a[i]; j++){
            if(a[i] & (1LL<<j)) has[j].push_back(i);
        }
    }

    for(int i = 0; i <= 60; i++){
        if(has[i].size() > 2){
            cout << "3\n";
            return 0;
        }

        if(has[i].size() > 1){
            adj[has[i][0]].push_back(has[i][1]);
            adj[has[i][1]].push_back(has[i][0]);
            edges.insert({has[i][0], has[i][1]});
        }
    }

    

    int ans = 1e9;
    for(auto [x,y] : edges){

        ans = min(ans, bfs(x, y));
    }

    cout << (ans == 1e9 ? -1 : ans) << "\n";




}