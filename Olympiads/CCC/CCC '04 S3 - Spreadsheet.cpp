#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int grid[15][15];



bool visited[15][15], marked[15][15];

vector<pii> adj[15][15];

bool check(string s){
    for(char c: s){
        if(!isdigit(c)) return false;
    }

    return true;
}

int dfs(int x, int y){
    if(grid[x][y] != -1) return grid[x][y];
    if(visited[x][y]) return -1;
    visited[x][y] = 1;

    int ans = 0;

   

    for(pii c : adj[x][y]){
        int cur = dfs(c.first, c.second);
        //if(x == 9 && y == 9) cout << cur << "\n";
        //if(x == 1 && y == 4) cout << c.first << " " << c.second << "\n";
        if(grid[c.first][c.second] == -1) return -1;
        ans += grid[c.first][c.second];
    }

    grid[x][y] = ans;
    return ans;
}


int main(){
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 9; j++){
            grid[i][j] = -1;
            string s; cin >> s;

            if(check(s)) grid[i][j] = stoi(s);
            else
                for(int k = 0; k < s.size()-1; k+=3){
                    if(s[k] == '+') continue;
                    adj[i][j].push_back({s[k] - 'A' + 1,s[k+1] - '0'});
                }
                
            
            

            
        }
    }

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 9; j++){
            if(!visited[i][j] && grid[i][j] == -1) grid[i][j] = dfs(i,j);
        }
    }

    

    for(int i =1; i <= 10; i++){
        for(int j = 1; j <= 9; j++){
            if(grid[i][j] == -1) cout << "* ";
            else cout << grid[i][j] << " ";
        }

        cout << "\n";
    }



}