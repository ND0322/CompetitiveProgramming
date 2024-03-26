#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 305;

int n, m, k, q, col[MAXN], cnt[MAXN][20][4], cur = 1,dp[35][20][MAXN][MAXN<<1];

bool vis[MAXN];

//n * k^4 might be too slow?

vector<int> adj[MAXN];

void dfs(int node){
    if(vis[node]) return;
    vis[node] = 1;

    cnt[cur][col[node]][0]++;
    cnt[cur][col[node]+1][1]++;
    cnt[cur][col[node]*2][2]++;
    cnt[cur][col[node]^15][3]++;

    for(int child : adj[node]) dfs(child);
}



int main(){
    cin >> n >> m >> k >> q;

    for(int i = 1; i <= n; i++) cin >> col[i];

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            cur++;
        }
    }

    //swap the query later
    
    for(int a = 1; a <= k; a++){
        for(int b = a; b <= k; b++){
            dp[a][b][1][n] = 0;
            for(int i = 1; i < cur; i++){
                for(int j = 0; j <= 2*n; j++){
                    if(dp[a][b][i][n] == -1) continue;
                    dp[a][b][i+1][]
                }
            }
        }
    }

    


}

