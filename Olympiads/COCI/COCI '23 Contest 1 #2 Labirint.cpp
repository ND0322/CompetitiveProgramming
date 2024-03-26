#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;


typedef pair<int,int> pii;

const int MAXN = 105;

int n,m;

int color[105][105][4];

bool visited[105][105];


unordered_map<char, int> bald;

//0 up
//1 right
//2 down
//3 left

int main(){

    bald['P'] = 0;
    bald['C'] = 1;
    bald['Z'] = 2;
    bald['N'] = 3;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string s; cin >> s;

        for(int j = 1; j < m; j++){
            color[i][j-1][1] = bald[s[j-1]];
            color[i][j][3] = bald[s[j-1]];
        }
    }

    

    for(int i = 0; i < n-1; i++){
        string s; cin >> s;

        for(int j = 0 ;j < m; j++){
            color[i][j][2] = bald[s[j]];
            color[i+1][j][0] = bald[s[j]];
        }
    }

    

    int q; cin >> q;

    while(q--){
        int x,y,a,b; cin >> x >> y >> a >> b;

        x--;
        y--;
        a--;
        b--;

        int ans = 1e9;

        for(int mask = 0; mask < 16; mask++){
            memset(visited, 0, sizeof(visited));

            visited[x][y] = 1;

            queue<pii> q;

            q.push({x,y});

            while(!q.empty()){
                int nx = q.front().first;
                int ny = q.front().second;

                q.pop();

                if(nx == a && ny == b){
                    ans = min(ans, __builtin_popcount(mask));
                    break;
                }

                vector<pair<pii,int>> children;

                if(nx - 1 >= 0 && !visited[nx-1][ny]) children.push_back({{nx-1,ny}, 0});
                if(ny - 1 >= 0 && !visited[nx][ny-1]) children.push_back({{nx,ny-1}, 3});
                if(nx + 1 < n && !visited[nx+1][ny]) children.push_back({{nx+1,ny}, 2});
                if(ny + 1 < m && !visited[nx][ny+1]) children.push_back({{nx,ny+1}, 1});

                for(pair<pii,int> c: children){
                    //cout << nx << " " << ny << " " << c.second << " " << color[nx][ny][c.second] << "\n";
                    if(mask & (1<<color[nx][ny][c.second])){
                        visited[c.first.first][c.first.second] = 1;
                        q.push({c.first.first, c.first.second});
                    }
                }
            }


        }

        cout << ans << "\n";
    }

    
}