#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

const int MAXN = 105;

typedef pair<int,int> pii;
typedef pair<pii,pii> help;

int n;

bool visited[MAXN][MAXN][MAXN], cloud[MAXN][MAXN][MAXN];

int main(){
    cin >> n;


    int xs,ys,zs; cin >> xs >> ys >> zs;
    int xe, ye, ze; cin >> xe >> ye >> ze;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                char c; cin >> c;

                if(c == '1') cloud[j][k][i] = 1;
            }
        }
    }

    queue<help> q;
    visited[xs][ys][zs] = 1;

    q.push({{xs,ys}, {zs, 0}});

    while(!q.empty()){
        int nx = q.front().first.first;
        int ny = q.front().first.second;
        int nz = q.front().second.first;
        int d = q.front().second.second;

        //cout << nx << ' ' << ny << " " << nz << " " << d << "\n";

        q.pop();


        if(nx == xe && ny == ye && nz == ze){
            cout << d << "\n";
            return 0;
        }

        vector<pair<pii, int>> children;

        if(nx+1 <= n) children.push_back({{nx+1, ny}, nz});
        if(nx-1 > 0) children.push_back({{nx-1, ny}, nz});

        if(ny+1 <= n) children.push_back({{nx, ny+1}, nz});
        if(ny-1 > 0) children.push_back({{nx, ny-1}, nz});

        if(nz+1 <= n) children.push_back({{nx, ny}, nz+1});
        if(nz-1 > 0) children.push_back({{nx, ny}, nz-1});

        for(pair<pii,int> c : children){
            if(!visited[c.first.first][c.first.second][c.second] && !cloud[c.first.first][c.first.second][c.second]){
                visited[c.first.first][c.first.second][c.second] = 1;
                q.push({{c.first.first, c.first.second},{c.second, d+1}});
            }
        }
    }

    cout << "-1\n";

    
}