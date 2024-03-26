#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1500;

typedef pair<int,int> pii;

int n, m, k, grid[MAXN][MAXN];

bool visited[MAXN][MAXN];

queue<pair<pii,pii>> q;
vector<pair<int,pii>> start;

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j]) start.push_back({grid[i][j], {i,j}});
        }
    }

    sort(start.begin(), start.end());

    for(pair<int,pii> i : start){
        q.push({{i.second.first,i.second.second}, {0, i.first}});
        visited[i.second.first][i.second.second] = 1;
    }

    while(!q.empty()){
        int nodex = q.front().first.first;
        int nodey = q.front().first.second;

        int d = q.front().second.first;
        int col = q.front().second.second;

        q.pop();

        if(d > k) continue;

        if(!grid[nodex][nodey]) grid[nodex][nodey] = col;
        
        vector<pii> children;

        if(nodex-1 >= 0) children.push_back({nodex-1, nodey});
        if(nodey-1 >= 0) children.push_back({nodex, nodey-1});
        if(nodex+1 < n) children.push_back({nodex+1, nodey});
        if(nodey+1 < m) children.push_back({nodex, nodey+1});

        for(pii c:children){
            if(!visited[c.first][c.second]){
                visited[c.first][c.second] = 1;
                q.push({{c.first, c.second}, {d+1, col}});
            }
        }
        
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << grid[i][j] << " ";
        cout << "\n";
    }

    


}