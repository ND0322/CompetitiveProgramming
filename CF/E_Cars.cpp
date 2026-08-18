#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, m, col[MAXN], in[MAXN], ans[MAXN], cnt;

bool flag = 1;

vector<pair<int,pair<int,int>>> edges;

vector<int> adj[MAXN], adjD[MAXN];

/*
intesect means two cars have opposite directions AND L is on the right of R
we just need to find a coloring 
*/

void dfs(int node){
    for(int child : adj[node]){
        if(col[child] != -1){
            if(col[child] == col[node]){
                flag = 0;
                return;
            }
            continue;
        }

        col[child] = !col[node];
        dfs(child);
    }
}

int main(){
    cin >> n >> m;

    memset(col, -1, sizeof(col));


    for(int i = 1; i <= m; i++){
        int t,x,y; cin >> t >> x >> y;

        edges.push_back({t,{x,y}});
        adj[x].push_back(y);
        adj[y].push_back(x);   
    }
    
    for(int i = 1; i <= n; i++){
        if(col[i] == -1){
            col[i] = 0;
            dfs(i);
        }
    }


    if(!flag){
        cout << "NO\n";
        return 0;
    }

    for(auto e : edges){
        auto [x,y] = e.second;
        if(col[x]) swap(x,y);

        //x is left
        if(e.first == 1){
            adjD[x].push_back(y);
            in[y]++;
        }
        else{
            adjD[y].push_back(x);
            in[x]++;
        }
    }


    queue<int> q;

    //topo
    for(int i = 1; i <= n; i++){
        if(!in[i]){
            ans[i] = ++cnt;
            q.push(i);
            
        }
    }

    while(q.size()){
        int node = q.front();

        q.pop();

        for(int child : adjD[node]){
            in[child]--;

            if(!in[child]){
                ans[child] = ++cnt;
                q.push(child);
            }
        }
    }


    for(int i = 1; i <= n; i++) flag &= ans[i] != 0;

    if(!flag){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        cout << (col[i] == 1 ? "R" : "L") << " " << ans[i] << "\n";
    }
    


}
