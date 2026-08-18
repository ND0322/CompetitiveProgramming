#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, m, mn, cnt, dist[MAXN];

vector<int> di = {1, 0, -1, 0};
vector<int> dj = {0, 1, 0, -1};



vector<vector<bool>> grid;
vector<vector<int>> comp;
vector<vector<char>> ans;
vector<pair<int,int>> adj[MAXN];

/*
process components from bottom left 

minimum fall distance of blocks in the component 
*/


void dfs(int x, int y){
    if(x <= 0 || y <= 0 || x > n || y > m || comp[x][y] || !grid[x][y]) return;
    comp[x][y] = cnt;

    for(int i = 0; i < 4; i++) dfs(x + di[i], y + dj[i]);
}

int main(){
    cin >> n >> m;

    grid = vector<vector<bool>>(n+1, vector<bool>(m+1, 0));
    comp = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    ans = vector<vector<char>>(n+1, vector<char>(m+1, '.'));

    for(int i = 1; i <= n; i++){
        string s; cin >> s;


        for(int j = 1; j <= m; j++) grid[n-i+1][j] = (s[j-1] == '#');
    }



    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(comp[i][j] || !grid[i][j]) continue;

            cnt++;
            dfs(i,j);
        }
    }

    for(int j = 1; j <= m; j++){
        int last = 0;
        int d = 0;
        for(int i = 1; i <= n; i++){
            d++;
            if(!comp[i][j]) continue;
            if(comp[i][j] != last){
                adj[last].push_back({comp[i][j], d-1});
                last = comp[i][j];
                d = 0;
            }
            else d = 0;
        }
    }


    for(int i =1;  i <= cnt; i++) dist[i] = 1e9;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,0});

    while(pq.size()){
        auto [d, node] = pq.top();

        pq.pop();

        for(auto [child, weight] : adj[node]){
            if(dist[child] > d + weight){
                dist[child] = d + weight;

                pq.push({dist[child], child});
            }

        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!comp[i][j] || !grid[i][j]) continue;

            ans[i-dist[comp[i][j]]][j] = '#';
        }
    }



    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= m; j++) cout << ans[i][j];
        cout << "\n";
    }



}