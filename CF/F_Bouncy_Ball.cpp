#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<vector<bool>> visited;
int n, m, endx,endy,startx,starty;

unordered_map<string,int> di = {{"D",1},{"U",-1}};
unordered_map<string,int> dj = {{"R",1},{"L",-1}};

int dfs(int nodex, int nodey, int dv, int dh){
    visited[nodex][nodey] = true;

    if(nodex == endx-1 && nodey == endy-1){
        return 0;
    }

    if(nodex == 0 && nodey == 0){
        return -1e9;
    }
    if(nodex == n-1 && nodey == 0){
        return -1e9;
    }
    if(nodex == 0 && nodey == m-1){
        return -1e9;
    }
    if(nodex == n-1 && nodey == m-1){
        return -1e9;
    }

    if(nodex == n-1 || nodex == 0){
        if(!visited[nodex][-dv])
        return dfs(nodex - dv,nodey+dh,-dv,dh) + 1;
    }
   
}



int main(){
    int t; cin >> t;

    while(t--){
        string dir;
        cin >>n >> m >> startx >> starty >> endx >> endy >> dir;

        visited = vector<vector<bool>>(n,vector<bool>(m,false));
        
    }
}