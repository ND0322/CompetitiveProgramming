#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#include <map>
using namespace std;

const int MAXN = 55;

typedef pair<int,int> pii;
typedef pair<pii,int> state;

map<char, int> di;
map<char, int> dj;

int n, m, distances[MAXN][MAXN][MAXN];

string cmd, s = "URDL";

deque<state> pq;

char grid[MAXN][MAXN];




int main(){
    di['L'] = 0;
    dj['L'] = -1;

    di['R'] = 0;
    dj['R'] = 1;

    di['U'] = -1;
    dj['U'] = 0;

    di['D'] = 1;
    dj['D'] = 0;


    cin >> n >> m;

    pii st, en;

    for(int i = 0; i < n; i++){
        string s; cin >> s;

        for(int j = 0; j < m; j++){
            if(s[j] == 'R') st = {i,j};
            if(s[j] == 'E') en = {i,j};

            grid[i][j] = s[j];
        }
    }

    cin >> cmd;

    memset(distances, 0x3f, sizeof(distances));

    distances[st.first][st.second][0] = 0;
    pq.push_back({{st.first,st.second},0});


    while(!pq.empty()){
        int x = pq.front().first.first;
        int y = pq.front().first.second;
        int i = pq.front().second;


        pq.pop_front();

        int nx, ny;

        for(char c: s){
            nx = x + di[c];
            ny = y + dj[c];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#'){
                if(distances[nx][ny][i] > distances[x][y][i] + 1){
                    distances[nx][ny][i] = distances[x][y][i] + 1;
                    pq.push_back({{nx,ny}, i});
                }

               

                
            }
        }

        if(i == cmd.size()) continue;

        nx = x+di[cmd[i]];
        ny = y+dj[cmd[i]];


        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#'){
            if(distances[nx][ny][i+1] > distances[x][y][i]){
                distances[nx][ny][i+1] = distances[x][y][i];
                pq.push_front({{nx,ny}, i+1});
            }
        }
        else{
            if(distances[x][y][i+1] > distances[x][y][i]){
                distances[x][y][i+1] = distances[x][y][i];
                pq.push_front({{x,y}, i+1});
            }
        }

        



    }

    int ans = 1e9;

    for(int i = 0; i <= cmd.size(); i++){
       
        ans = min(ans, distances[en.first][en.second][i]);
    }
    
    cout << ans << "\n";


}