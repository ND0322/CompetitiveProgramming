#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;


int n, m, ans;
vector<pair<int,int>> adj[MAXN];

bool luck[MAXN], vis[MAXN], used[MAXN];



void dfs(int node){
    vis[node] = 1;

    for(pair<int,int> c:adj[node]){
        if(!vis[c.first]){
            dfs(c.first);


            //greedy
            if(!luck[c.first]){
                luck[c.first] = 1;
                luck[node] ^= 1;
                ans++;
                used[c.second] = 1;
            }
        }
    }
}


int main(){
    cin >> n >> m;


    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back({y,i});
        adj[y].push_back({x,i});

       
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++) cnt += luck[i];

    cout << cnt << "\n";

    cout << m-ans << "\n";

    for(int i = 1; i <= m; i++){
        if(!used[i]){
            cout << i << " ";
        }
    }

    cout << "\n";
}


