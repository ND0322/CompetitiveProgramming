#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1005;

typedef pair<int,int> pii;

int n, m, grid[MAXN][MAXN];

bool visited[MAXN][MAXN][2][2][4];

//pii slide[MAXN][MAXN][2][4];

vector<int> di = {-1, 0, 1, 0};
vector<int> dj = {0, 1, 0, -1};

queue<pair<pair<pii,pii>, pii>> q;

int main(){
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            //slide[i][j][0] = slide[i][j][1] = slide[i][j][2]= slide[i][j][3] = {-1,-1};
        }   
    }

    //0 up
    //1 right
    //2 down
    //3 left

    q.push({{{0,0}, {0,0}}, {0,0}});
    visited[0][0][0][0][0] = 1;
    visited[0][0][0][0][1] = 1;
    visited[0][0][0][0][2] = 1;
    visited[0][0][0][0][3] = 1;

    while(!q.empty()){
        int nx = q.front().first.first.first;
        int ny = q.front().first.first.second;
        bool sm = q.front().first.second.first;
        bool must = q.front().first.second.second;
        int dir = q.front().second.first;
        int d = q.front().second.second;

        q.pop();

        if(nx == n-1 && ny == m-1){
            cout << d << "\n";
            return 0;
        }

        //do must part here

        if(must){
            if(nx + di[dir] < 0 || nx + di[dir] >= n || ny + dj[dir] < 0 || ny + dj[dir] >= m){
                if(!visited[nx][ny][0][0][0]){
                    visited[nx][ny][0][0][0] = 1;
                    visited[nx][ny][0][0][1] = 1;
                    visited[nx][ny][0][0][2] = 1;
                    visited[nx][ny][0][0][3] = 1;
                    q.push({{{nx,ny}, {0,0}}, {dir,d}});
                    
                }
                continue;
            }

            if(grid[nx+di[dir]][ny+dj[dir]] == 0 || grid[nx+di[dir]][ny+dj[dir]] == 3){
                if(!visited[nx][ny][0][0][0]){
                    visited[nx][ny][0][0][0] = 1;
                    visited[nx][ny][0][0][1] = 1;
                    visited[nx][ny][0][0][2] = 1;
                    visited[nx][ny][0][0][3] = 1;
                    q.push({{{nx,ny}, {0,0}}, {dir,d}});
                }
                continue;
            }

            if(grid[nx+di[dir]][ny+dj[dir]] == 1){
                if(!visited[nx+di[dir]][ny+dj[dir]][0][0][0]){
                    visited[nx+di[dir]][ny+dj[dir]][0][0][0] = 1;
                    visited[nx+di[dir]][ny+dj[dir]][0][0][1] = 1;
                    visited[nx+di[dir]][ny+dj[dir]][0][0][2] = 1;
                    visited[nx+di[dir]][ny+dj[dir]][0][0][3] = 1;
                    q.push({{{nx+di[dir],ny+dj[dir]}, {0,0}}, {dir,d+1}});
                }
                continue;
            }

            if(grid[nx+di[dir]][ny+dj[dir]] == 2){
                if(!visited[nx+di[dir]][ny+dj[dir]][1][0][0]){
                    visited[nx+di[dir]][ny+dj[dir]][1][0][0] = 1;
                    visited[nx+di[dir]][ny+dj[dir]][1][0][1] = 1;
                    visited[nx+di[dir]][ny+dj[dir]][1][0][2] = 1;
                    visited[nx+di[dir]][ny+dj[dir]][1][0][3] = 1;
                    q.push({{{nx+di[dir],ny+dj[dir]}, {1,0}}, {dir,d+1}});
                }
                continue;
            }

             if(grid[nx+di[dir]][ny+dj[dir]] == 4){
                if(!visited[nx+di[dir]][ny+dj[dir]][0][1][0]){
                    visited[nx+di[dir]][ny+dj[dir]][0][1][0] = 1;
                    visited[nx+di[dir]][ny+dj[dir]][0][1][1] = 1;
                    visited[nx+di[dir]][ny+dj[dir]][0][1][2] = 1;
                    visited[nx+di[dir]][ny+dj[dir]][0][1][3] = 1;
                    q.push({{{nx+di[dir],ny+dj[dir]}, {0,1}}, {dir,d+1}});
                }
                continue;
            }

            
        }

        vector<pair<pii,int>> children;
        //x,y,dir

        if(nx-1 >= 0) children.push_back({{nx-1,ny}, 0});
        if(nx+1 < n) children.push_back({{nx+1,ny}, 2});
        if(ny-1 >= 0) children.push_back({{nx,ny-1}, 3});
        if(ny+1 < m) children.push_back({{nx,ny+1}, 1});

        for(pair<pii,int> p : children){
            int cx = p.first.first;
            int cy = p.first.second;
            int cd = p.second;

            if(!grid[cx][cy]) continue;
            if(grid[cx][cy] == 3){
                if(!sm) continue;

                if(!visited[cx][cy][1][0][cd]){
                    visited[cx][cy][1][0][cd] = 1;
                    q.push({{{cx,cy}, {1,0}}, {cd,d+1}});
                }
            }

            if(grid[cx][cy] == 1){
                if(!visited[cx][cy][sm][0][cd]){
                    visited[cx][cy][sm][0][cd] = 1;
                    q.push({{{cx,cy}, {sm,0}}, {cd,d+1}});
                }
            }

            if(grid[cx][cy] == 2){
                if(!visited[cx][cy][1][0][cd]){
                    visited[cx][cy][1][0][cd] = 1;
                    q.push({{{cx,cy}, {1,0}}, {cd,d+1}});
                }
            }

            if(grid[cx][cy] == 4){
                if(!visited[cx][cy][0][1][cd]){
                    visited[cx][cy][0][1][cd] = 1;
                    q.push({{{cx,cy}, {0,1}}, {cd,d+1}});
                }
            }
        }
    
    }

	cout << "-1\n";

}