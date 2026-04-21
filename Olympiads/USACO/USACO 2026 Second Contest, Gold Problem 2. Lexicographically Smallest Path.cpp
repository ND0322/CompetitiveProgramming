#include <bits/stdc++.h>
#include <iostream>

using namespace std;


using namespace std;

const int MAXN = 2e5+5;

vector<pair<int,int>> adj[MAXN];
int dist[MAXN];

bool vis[MAXN];

char best[MAXN];


/*
propagate level by level
We can only transition to nodes of the lowest color 
each node will only have one color of outgoing edge 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;


        for(int i = 1; i <= n; i++){
            adj[i].clear();
            best[i] = 'z';
            dist[i] = -1;
            vis[i] = 0;
        }


        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;

            char c; cin >> c;

            if(best[x] == c) adj[x].push_back({y, c-'a'});
            if(best[x] > c){
                adj[x] = {{y, c - 'a'}};
                best[x] = c;
            }

            if(best[y] == c) adj[y].push_back({x, c-'a'});
            if(best[y] > c){
                adj[y] = {{x, c - 'a'}};
                best[y] = c;
            }
        }

        queue<int> q;

        set<pair<int,int>> nxt;

        q.push(1);
        dist[1] = 0;
        vis[1] = 1;

        int lowest = 1e9;
        int last = 0;
        while(1){

            if(q.empty()){
                
                for(auto [child, col] : nxt){
                    if(col != lowest) continue;
                    vis[child] = 1;
                    dist[child] = last + 1;
                    q.push(child);
                }
                nxt.clear();

                if(q.empty()) break;

                continue;
            }
            int node = q.front();
            last = dist[node];

            q.pop();

            for(auto [child, col] : adj[node]){
                if(!vis[child]){
                    if(col == lowest) nxt.insert({child, col});
                    else if(col < lowest){
                        nxt = {{child, col}};
                        lowest = col;
                    }
                }
                
            }


        }

        for(int i = 1; i <= n; i++) cout << dist[i] << " ";
        cout << "\n";


        
    }
}