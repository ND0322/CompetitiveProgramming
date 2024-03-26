#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 65;

int n;

char grid[MAXN][MAXN];

bool vis[MAXN][MAXN][MAXN][MAXN];

vector<int> di = {1,0,-1,0}, dj = {0,1,0,-1};

int main(){
    cin >> n;

    vector<pair<int,int>> src;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];

            if(grid[i][j] == 'P') src.push_back({i,j});
        }
    }

    queue<pair<pair<pair<int,int>,pair<int,int>>, int>> q;

    q.push({{src[0], src[1]}, 1});

    vis[src[0].first][src[0].second][src[1].first][src[1].second] = 1;

    while(!q.empty()){
        auto [ax,ay] = q.front().first.first;
        auto [bx,by] = q.front().first.second;

        int d = q.front().second;

        cout << ax << " " << ay << " " << bx << " " << by << "\n";

        q.pop();

        if(ax == bx && ay == by){
            cout << d << "\n";
            return 0;
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                int xx = ax+di[i];
                int xy = ay+dj[i];
                int yx = bx+di[j];
                int yy = by+dj[j];

                if(xx >= 0 && xx < n && xy >= 0 && xy < n && yx >= 0 && yx < n && yy >= 0 && yy < n){
                    if&& grid[xx][xy] != '#' && grid[yx][yy] != '#' && !vis[xx][xy][yx][yy] 
                    vis[xx][xy][yx][yy] = 1;
                    q.push({{{xx,xy}, {yx,yy}},d+1});
                }
            }
        }        
    }

    cout << "-1\n";
    

    
}