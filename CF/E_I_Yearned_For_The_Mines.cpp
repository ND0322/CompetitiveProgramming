#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;


/*
bool chain(int node){
    //find a leaf

    if(comp.size() == 2 || comp.size() == 1){
        ord = comp;
        return 1;
    }

    int cnt = 0;

    dfs(node, -1);
    
    int u = -1;

    for(int i : comp){
        cnt += deg[i] == 0;
        if(deg[i] == 0) u = i;
    }


    ord.clear();

    for(int i : comp) deg[i] = 0;
    dfs(u, -1);

    for(int i : comp){
        if(deg[i] > 1){
            return 0;
        }
    }

    return 1;
}
*/





int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        ans.clear();

        for(int i = 1;  i<= n; i++){
            sz[i] = 0;
            adj[i].clear();
            marked[i] = 0;
            comp.push_back(i);
        }


        for(int i =1 ; i <= n-1; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    

        build(1,-1, 0);

        int sz = 0;
        for(auto i : ans) sz += i.second.size();

        cout << sz << "\n";

        for(auto i : ans){
            for(auto j : i.second) cout << j.first << " " << j.second << "\n";
        }
        
        
    }
}