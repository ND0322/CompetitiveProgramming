#include <bits/stdc++.h>
#include <iostream>
#include <set>


using namespace std;

const int MAXN = 3005;

int n, deg[MAXN][MAXN], cnt;

bool marked[MAXN][MAXN];

set<pair<int,int>> extra;

void dfs(int x, int y){
    if(marked[x][y]) return;
    deg[x+1][y]++;
    deg[x][y+1]++;
    deg[x-1][y]++;
    deg[x][y-1]++;
    marked[x][y] = 1;
    cnt++;

    vector<pair<int,int>> children;

    if(deg[x+1][y] == 3) children.push_back({x+1,y});
    if(deg[x-1][y] == 3) children.push_back({x-1,y});
    if(deg[x][y+1] == 3) children.push_back({x,y+1});
    if(deg[x][y-1] == 3) children.push_back({x,y-1});
    if(deg[x][y] == 3) children.push_back({x,y});

    for(auto [cx, cy] : children){
        if(!marked[cx][cy]) continue;
        if(!marked[cx-1][cy]){
            dfs(cx-1, cy);
            extra.insert({cx-1,cy});
        }
        if(!marked[cx+1][cy]){
            dfs(cx+1, cy);
            extra.insert({cx+1, cy});
        }
        if(!marked[cx][cy-1]){
            dfs(cx, cy-1);
            extra.insert({cx,cy-1});
        }
        if(!marked[cx][cy+1]){
            dfs(cx, cy+1);
            extra.insert({cx, cy+1});
        }
        
    }


}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;

        x += 1500;
        y += 1500;

        dfs(x,y);

        cout << cnt - i << "\n";
    }


}