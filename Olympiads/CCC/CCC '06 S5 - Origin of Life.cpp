#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int n, m, a,b,c;

bool visited[1<<20], grid[5][6], nxt[5][6];
vector<int> adj[1<<20];
queue<pair<int,int>> q;


/*
.****
.****
.****
.****

= this thing
01111011110111101111
*/

//11111100001010011011

int main(){
    cin >> m >> n >> a >> b >> c;


    for(int mask = 0; mask < 1<<(n*m); mask++){
        for(int j = 0; j < (n*m); j++){
            grid[j/n][j%n] = (mask & (1<<j));
        }


       

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0;

                if(i+1 < m){
                    if(j + 1 < n) cnt += grid[i+1][j+1];
                    if(j-1 >= 0) cnt += grid[i+1][j-1];
                    cnt += grid[i+1][j];
                }
                if(i - 1 >= 0){
                    if(j + 1 < n) cnt += grid[i-1][j+1];
                    if(j-1 >= 0) cnt += grid[i-1][j-1];
                    cnt += grid[i-1][j];
                }
                if(j+1 < n) cnt += grid[i][j+1];
                if(j-1 >= 0) cnt += grid[i][j-1];

                nxt[i][j] = 1;
                if(grid[i][j] && (cnt < a || cnt > b)) nxt[i][j] = 0;
                if(!grid[i][j] && !(cnt > c)) nxt[i][j] = 0;
                
            }
        }
        
        int child = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) child |= (nxt[i][j]<<(i*n + j));
        }
        

        adj[child].push_back(mask);     
    }

    int start = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            start |= ((c == '*')<<(i*n + j));
        }
    }

    visited[start] = 1;
    q.push({start, 0});

    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;

        q.pop();

        if(adj[node].empty()){
            cout << d << "\n";
            return 0;
        }

        for(int child : adj[node]){
            if(!visited[child]){
                visited[child] = 1;
                q.push({child, d+1});
            }
        }
    }

    cout << "-1\n";

    
}

