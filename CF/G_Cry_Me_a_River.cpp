#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, m, q;

set<int> deg[MAXN];

bool dp[MAXN][2];

vector<int> adj[MAXN];
/*
After paitning a red node we can invalidate all things in a path 

0 is cry turn

dp value is 1 for b wins 

let dp be 1 if red node
dp[u][0] -> 0, dp[p][1] -> 0
dp[u][1] -> 0, p deg--

dp[p][0] -> 0 when deg is 0
*/

void upd(int node, bool turn){



    if(!turn){
        for(int child : adj[node]){
            if(dp[child][1]){
                dp[child][1] = 0;
                upd(child, 1);
            }
        }
    }
    else{
        for(int child : adj[node]){
            if(deg[child].find(node) != deg[child].end()) deg[child].erase(node);
            if(deg[child].size()) continue;
            dp[child][0] = 0;
            upd(child, 0);
        }
        
    }

    
}

int main(){
    int tt; cin >> tt;
    

    while(tt--){
        cin >> n >> m >> q;

        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i][1] = 1;
            deg[i].clear();
            adj[i].clear();
        }

        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;


            adj[y].push_back(x);
            deg[x].insert(y);
        }


        while(q--){
            int t, u; cin >> t >> u;

            if(t == 1){

                dp[u][0] = 0;
                dp[u][1] = 0;
            
                upd(u, 0);
                upd(u, 1);

                
            }
            else cout << (dp[u][0] ? "YES\n" : "NO\n");
        }
    }
}