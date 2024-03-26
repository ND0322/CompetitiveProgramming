#include <bits/stdc++.h>   
#include <iostream>

using namespace std;

const int MAXN = 105;

typedef pair<int,int> pii;

int n, m;

bool visited[MAXN][MAXN], on[MAXN][MAXN];

vector<pii> nxt[MAXN][MAXN];

bool check(int nodex, int nodey){
    if(nodex <= 0 || nodex > n || nodey <= 0 || nodey > n) return 0;
    return visited[nodex][nodey] && on[nodex][nodey];
}

void dfs(int nodex, int nodey){

   
    if(visited[nodex][nodey]) return;
    if(!on[nodex][nodey]) return;
    visited[nodex][nodey] = 1;

    //cout << nodex << " " << nodey << "\n";

    for(pii p : nxt[nodex][nodey]){
        if(!on[p.first][p.second]){
            on[p.first][p.second] = 1;
            
            if(check(p.first-1,p.second) || check(p.first+1,p.second) || check(p.first,p.second-1) || check(p.first,p.second+1)) dfs(p.first, p.second);
        }
       
    }

    dfs(nodex-1, nodey);
    dfs(nodex+1, nodey);
    dfs(nodex, nodey-1);
    dfs(nodex, nodey+1);
}


int main(){
    //freopen("lightson.in", "r", stdin);
    //freopen("lightson.out", "w", stdout);
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y, a,b; cin >> x >> y >> a >> b;

        nxt[x][y].push_back({a,b});
    }

    on[1][1] = 1;
    dfs(1,1);

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cnt += on[i][j];
    }

    cout << cnt << "\n";
}