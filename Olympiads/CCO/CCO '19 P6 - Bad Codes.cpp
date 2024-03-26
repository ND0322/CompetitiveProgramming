#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 120;

int n,m, tr[MAXN][2], tot = 1;

bool visited[MAXN][MAXN], out[MAXN];

//really cool problem

void insert(string s){
    int u = 1;
    
    for(int i = 0; i < s.size(); i++){

        if(!tr[u][s[i] == '1']) tr[u][s[i] == '1'] = ++tot;
        u = tr[u][s[i] == '1'];
    }

    out[u] = 1;
}

int main(){

    cin >> n >> m;

    while(n--){
        string s; cin >> s;
        insert(s);
    }

    queue<pair<pair<int,int>,int>> q;

    visited[1][1] = 1;
    q.push({{1,1},0});

   

    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int d = q.front().second;

        q.pop();

        //cout << i << " " << j << " " << d << "\n";


        if(out[i] && out[j] && i != j){
            cout << d << "\n";
            return 0;
        }

        
        vector<pair<int,int>> children;

        if(tr[i][0] && tr[j][0]) children.push_back({tr[i][0], tr[j][0]});
        if(tr[i][1] && tr[j][1]) children.push_back({tr[i][1], tr[j][1]});
        if(out[j] && tr[i][1] && tr[1][1]) children.push_back({tr[i][1], tr[1][1]});
        if(out[j] && tr[i][0] && tr[1][0]) children.push_back({tr[i][0], tr[1][0]});
        if(out[i] && tr[1][1] && tr[j][1]) children.push_back({tr[1][1], tr[j][1]});
        if(out[i] && tr[1][0] && tr[j][0]) children.push_back({tr[1][0], tr[j][0]});

        for(auto [cx, cy] : children){
            if(visited[cx][cy]) continue;
            visited[cx][cy] = 1;
            q.push({{cx,cy},d+1});
        }

    }

    cout << "-1\n";

}
