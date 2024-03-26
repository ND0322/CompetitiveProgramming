#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n, m, q, parents[MAXN];

vector<pair<int,int>> adj[MAXN];

vector<pair<int,pair<int,int>>> edges;

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

bool uni(int x,int y){
    x = find(x);
    y = find(y);

    if(x == y) return false;

    parents[x] = y;

    return true;
}

bool dfs(int node, int par, int b, int w){
    if(node == b) return 1;

    for(auto [child, weight] : adj[node]){
        if(child == par) continue;
        if(weight >= w){
            if(dfs(child,node,b,w)) return 1;
        }
    }

    return 0;
}
int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        edges.push_back({c,{x,y}});
    }

    vector<pair<int,pair<int,int>>> tmp = edges;


    sort(tmp.rbegin(), tmp.rend());

    for(int i = 1; i <= n; i++){
        adj[i].clear();
        parents[i] = i;
    }



    for(pair<int,pair<int,int>> i : tmp){
        if(uni(i.second.first, i.second.second)){
            adj[i.second.first].push_back({i.second.second, i.first});
            adj[i.second.second].push_back({i.second.first, i.first});
        }
    }

    cin >> q;

    while(q--){
        int t; cin >> t;


        if(t == 1){
            int i, x; cin >> i >> x;

            

            edges[i-1].first = x;

            vector<pair<int,pair<int,int>>> tmp = edges;

            sort(tmp.rbegin(), tmp.rend());

            for(int i = 1; i <= n; i++){
                adj[i].clear();
                parents[i] = i;
            }



            for(pair<int,pair<int,int>> i : tmp){
                if(uni(i.second.first, i.second.second)){
                    adj[i.second.first].push_back({i.second.second, i.first});
                    adj[i.second.second].push_back({i.second.first, i.first});

                    //cout << i.second.first << " " << i.second.second << " " << i.first << "\n";
                }
            }

            //cout << "\n";
        }
        else{
            int x,y,c; cin >> x >> y >> c;

            cout << dfs(x,-1,y,c) << "\n";
        }
    }
}