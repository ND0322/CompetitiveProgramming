#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1005;

int n, m, dp[MAXN][MAXN], color[MAXN], cnt;
vector<int> adj[MAXN],opt[MAXN][2];
bool vis[MAXN], rebuild[MAXN][MAXN];

int solve(int i, int a, int b){
    if(i == cnt) return abs(a - b);

    if(dp[i][a] == -1){
        int res = solve(i+1, a + opt[i][0].size(), b + opt[i][1].size());
        int sec = solve(i+1, a + opt[i][1].size(), b + opt[i][0].size());
        if(res <= sec){
            dp[i][a] = res;
            rebuild[i][a] = 0;
        }
        else{
            dp[i][a] = sec;
            rebuild[i][a] = 1;
        }
    }

    return dp[i][a];
}

void dfs(int i, int a){
    if(i == cnt) return;

    
    for(int j : opt[i][rebuild[i][a]]) color[j] = 1;
    for(int j : opt[i][!rebuild[i][a]]) color[j] = 2;
    dfs(i+1, a + opt[i][rebuild[i][a]].size());
    
    
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

  

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            color[i] = 0;
            
            queue<pair<int,bool>> q;

            q.push({i, 0});
            opt[cnt][0].push_back(i);

            while(!q.empty()){
                int node = q.front().first;
                int col = q.front().second;

                q.pop();

                for(int child : adj[node]){
                    if(vis[child] && color[child] != !col){
                        cout << "-1\n";
                        return 0;
                    }

                    if(!vis[child]){
                        vis[child] = 1;
                        color[child] = !col;
                        opt[cnt][!col].push_back(child);

                        q.push({child, !col});
                    }
                }
            }

            cnt++;
        }
    }

    memset(dp,-1,sizeof(dp));

    solve(0,0,0);

    dfs(0,0);

    for(int i = 1; i <= n; i++) cout << color[i];
    cout << "\n";



   

    
}