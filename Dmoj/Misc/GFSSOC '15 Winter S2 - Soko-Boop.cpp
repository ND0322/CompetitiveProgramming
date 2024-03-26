#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 35;

//kinda annoying grid question

vector<int> di = {1,0,-1,0};
vector<int> dj = {0,1,0,-1};

int n,m;

typedef pair<int,int> pii;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN][MAXN];

int main(){
    cin >> n >> m;

    int sx,sy,ex,ey,bx,by;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];

            if(grid[i][j] == 'P'){
                sx = i;
                sy = j;
            }
            if(grid[i][j] == 'B'){
                bx = i;
                by = j;
            }
            if(grid[i][j] == 'X'){
                ex = i;
                ey = j;
            }
        }
    } 

    queue<pair<pair<pii,pii>,int>> q;
    q.push({{{sx,sy},{bx,by}},0});
    visited[sx][sy][bx][by] = 1;

    while(!q.empty()){
        int x = q.front().first.first.first;
        int y = q.front().first.first.second;
        int bx = q.front().first.second.first;
        int by = q.front().first.second.second;
        int d = q.front().second;

        q.pop();

        //cout << x << " " << y << " " << bx << " " << by << " " <<d << "\n";

        if(bx == ex && by == ey){
            cout << d << "\n";
            return 0;
        }

        for(int i = 0; i < 4; i++){
            int cx = x+di[i];
            int cy = y+dj[i];
            int nx = bx,ny = by;

            if(cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
            if(grid[cx][cy] == '#') continue;
            if(bx == cx && by == cy){
                nx = bx + di[i];
                ny = by + dj[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(grid[nx][ny] == '#') continue;
            }

            if(visited[cx][cy][nx][ny]) continue;

            visited[cx][cy][nx][ny] = 1;

            q.push({{{cx,cy},{nx,ny}},d+1});   
        }
    }

    cout << "-1\n";

    
}