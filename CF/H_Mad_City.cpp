#include <bits/stdc++.h>
#include <iostream>

using namespace std;



const int MAXN = 2e5+5;

int n,a,b,c;

vector<int> adj[MAXN];
bool visited[MAXN];

bool dfs(int node, int par){
    visited[node] = 1;

    for(int child:adj[node]){
        if(child==par) continue;

        if(visited[child]){
            c = child;
            return true;
        }

        if(dfs(child,node)) return true;
    }

    return false;
}

int dfs1(int node){
    visited[node] = 1;

    int ans = 1e9;

    for(int child:adj[node]){
        if(child == c) return 1;
        if(!visited[child]){
            ans = min(ans,dfs1(child)+1);
        }
    }

    return ans;
}





int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n >> a >> b;

        //a is marc b is val

        fill(visited,visited+n+1,false);
        fill(adj,adj+n+1,vector<int>());


        for(int i = 0; i < n; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(b,0);

        

        int distA = 1e9;
        int distB = 0;

        fill(visited+1,visited+n+1,false);

        if(a == c) distA = 0;
        distA = min(distA,dfs1(a));

        fill(visited+1,visited+n+1,false);

        if(b != c) distB = dfs1(b);


        cout << (distB < distA ? "YES" : "NO") << "\n";
    }
    








}

