#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;

int n, m, k, q, col[MAXN], cnt[MAXN][20][4], cur = 1;

bool dp[35][20][MAXN][MAXN<<1], vis[MAXN];

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
            
        }
    }

    


}

