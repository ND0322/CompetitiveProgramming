#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void dfs(int node, vector<int> adj[],vector<bool>& visited){
    visited[node] = true;

    for(int child:adj[node]){
        if(!visited[child]){
            dfs(child,adj,visited);
        }
    }
}

void dfs2(int node, vector<int> adj[], vector<bool>& visited, vector<int>& cur){
    visited[node] = true;
    cur.push_back(node);

    for(int child:adj[node]){
        if(!visited[child]){
            dfs2(child,adj,visited,cur);
        }
    }
}

int main(){
    // approach: model the connections as a graph. The max will be the number of components and the min will be the number of cyclic components + 1 if there is at least 1 acyclic component

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> degree(n+1,0);
        vector<int> adj[n+1];
        vector<bool> visited(n+1,false);

        for(int i =1; i <= n; i++){
            int x; cin >> x;

            if(find(adj[i].begin(),adj[i].end(),x) == adj[i].end()){
                adj[x].push_back(i);
                adj[i].push_back(x);

                degree[x]++;
                degree[i]++;
            }

            
        }

        int numC = 0;


        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                numC++;
                dfs(i,adj,visited);
            }
        }

        int numCC = 0;

        visited = vector<bool>(n+1,false);
        vector<int> cur;

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                cur.clear();
                dfs2(i,adj,visited,cur);
                int flag = 1;
                for(int node:cur){
                    if(degree[node] == 2){
                        continue;
                    }
                    flag = 0;
                    break;
                }

                if(flag == 1){
                    numCC++;
                }

            }
        }

        int a = bool(numC - numCC);
        //cout << numCC << endl;
        cout << numCC + a << " " << numC<< "\n";

   

    }
}