#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;

typedef pair<int,int> pii;

int n,m, ans[MAXN*MAXN], cur, b, w, parents[MAXN];

vector<pair<int,pii>> adj[MAXN];

vector<pair<pii,pii>> edges;

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }

    return x;
}

bool uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return false;
    
    parents[x] = y;

    return true;
}

bool dfs(int node, int par){
    if(node == b) return true;

    bool check = false;

    for(pair<int,pii> c :adj[node]){
        int child = c.first;
        int weight = c.second.first;
        int id = c.second.second;

        if(id == cur) continue;
        if(child == par) continue;

        //replacing this edge can still reach the endpoint

        if(dfs(child,node)){
            if(weight == w){
                ans[cur] = 1;
                ans[id] = 1;
            }
            
            check = true;
        }

        
    }

    return check;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        edges.push_back({{c,i}, {x,y}});
    }

    for(int i = 1; i <= n; i++) parents[i] = i;

    sort(edges.begin(), edges.end());

    int cnt = 0;

    for(pair<pii,pii> edge : edges){
        if(cnt == n-1) break;

        int weight = edge.first.first;
        int id = edge.first.second;
        int x = edge.second.first;
        int y = edge.second.second;

        //cout << x << " " << y << " " << weight << "\n";

        if(uni(x,y)){
            ans[id] = 2;
            adj[x].push_back({y,{weight,id}});
            adj[y].push_back({x,{weight,id}});
            cnt++;

 
        }
    }

    

    for(pair<pii,pii> edge : edges){
        int weight = edge.first.first;
        int id = edge.first.second;
        int x = edge.second.first;
        int y = edge.second.second;

        if(ans[id] == 2) continue;

        cur = id;
        b = y;
        w = weight;

        dfs(x,-1);


        
    }

    for(int i = 0; i < m; i++){
        if(!ans[i]) cout << "not useful\n";
        if(ans[i] == 1) cout << "so so\n";
        if(ans[i] == 2) cout << "useful\n";
    }
}
