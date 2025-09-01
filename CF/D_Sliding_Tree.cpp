#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 2e5+5;

int n, deg[MAXN], depth[MAXN], v;

vector<int> adj[MAXN];

vector<int> dia;

/*
find the center of the tree and operate the first bad thing on the left or right 
*/



void dfs(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;
        depth[child] = depth[node]+1;
        dfs(child, node);
    }
}


bool build(int node, int par){
    if(node == v){
        dia.push_back(node);
        return 1;
    }

    for(int child : adj[node]){
        if(child == par) continue;

        if(build(child, node)){
            dia.push_back(node);
            return 1;
        }
    }

    return 0;
}


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        dia.clear();
        v = 0;
        for(int i = 1; i <= n; i++){
            depth[i] = 0;
            adj[i].clear();
            deg[i] = 0;
        }

        for(int i = 1; i <= n-1; i++){
            int x,y; cin >> x >> y;

            deg[x]++;
            deg[y]++;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        
        dfs(1,-1);

        int mx = 0;
        int u = 0;
        for(int i = 1; i <= n; i++){
            if(depth[i] > mx){
                mx = depth[i];
                u = i;
            }
        }  



        for(int i = 1; i <= n; i++) depth[i] = 0;
        dfs(u, -1);
        mx = 0;
        for(int i =1 ; i <= n; i++){
            if(depth[i] > mx){
                mx = depth[i];
                v = i;
            }
        }


        dia.push_back(-1);

        build(u, -1);

        int ans = -1;
        
        for(int i = ((int)dia.size()) / 2; i >= 1; i--){

            if(deg[dia[i]] > 2){
                ans = i;
                break;
            }
        } 
        
        if(ans != -1){
            cout << dia[ans+1] << " " << dia[ans] << " " << dia[ans-1] << "\n";
            continue;
        }

        for(int i = ((int)dia.size()) / 2; i < dia.size(); i++){
            if(deg[dia[i]] > 2){
                ans = i;
                break;
            }
        }

        if(ans != -1){
            cout << dia[ans-1] << " " << dia[ans] << " " << dia[ans+1] << "\n";
            continue;
        }

        cout << "-1\n";
        
    }
}