#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4e4+5;

int n,m, par[MAXN];

bool p[MAXN], vis[MAXN];
vector<int> adj[MAXN], path;

void dfs(int node){

    if(node == n) return;

    
    vis[node] = 1;


    for(int child : adj[node]){
        if(!vis[child]){
            par[child] = node;
            dfs(child);
        }
    }
}

void dfs2(int node){
    if(!par[node]){
        path.push_back(1);
        p[node] = 1;
        return;
    }

    dfs2(par[node]);
    path.push_back(node);
    p[node] = true;
}

bool dfs3(int node){
    //cout << "d " << node << "\n";
    if(p[node]) return true;

    
    

    vis[node] = 1;

    for(int child:adj[node]){
        if(!vis[child]){
            if(dfs3(child)) return true;
        }
    }

    return false;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;

    

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

        
    }

    dfs(1);
    dfs2(n);

    //for(int i:path) cout << i << " ";
    //cout << "\n";

    //for(int i: adj[2]) cout << i << "\n";
    
    if(*path.rbegin() != n){
        cout << "No\n";
        return 0;
    }

    fill(vis+1,vis+1+n,0);

    for(int i = 0; i < path.size()-1; i++){

        vis[path[i]] = 1;

        //cout << path[i] << "\n";
        for(int child : adj[path[i]]){
            
            if(!vis[child] && child != path[i+1]){
                //cout << child << "\n";
                if(dfs3(child)){
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
}

