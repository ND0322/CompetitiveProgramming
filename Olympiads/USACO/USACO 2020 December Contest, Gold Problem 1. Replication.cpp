#include <bits/stdc++.h>
#include <iostream>

using namespace std;
const int MAXN = 105;


int n, k;

bool vis[MAXN][MAXN][MAXN];

char grid[MAXN][MAXN];

vector<int> di = {1,0,-1,0}, dj = {0,1,0,-1};


int main(){
   cin >> n >> k;

   for(int i = 0; i <= n+1; i++){
      for(int j = 0; j <= n+1; j++) grid[i][j] = '#';
   }
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++) cin >> grid[i][j];
   }


   for(int l = 1; l <= n; l++){
      //we can do at most i times


      queue<pair<int,pair<int,int>> q;

      for(int i = 1; i <= n; i++){
         for(int j = 1; j <= n; j++){
            if(vis[i][j][l-1]) q.push({0,{i,j}});
         }
      }

      while(q.size()){
         int d = q.front().first;

         auto[x,y] = q.front().second;

         q.pop();

         if(d == k) continue;

         for(int i = 0; i < 4; i++){
            int nx = x + di[i];
            int ny = y + dj[i];

            //this might be a global vis array
            if(vis[nx][ny][l]) continue;
            if(grid[nx][ny] == '#') continue;
            
            vis[nx][ny][l] = 1;

            q.push({d+1, {nx, ny}});
         }
      }
   }




}