#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, tot;

bool vis[MAXN];

vector<int> adj[MAXN], adjT[MAXN];

int dfs(int node){
    int sm = 0;
    for(int child : adjT[node]){
        sm += dfs(child);
    }
    tot += sm+1;
    return sm+1;
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int k; cin >> k;

        while(k--){
            int x; cin >> x;

            adj[x].push_back(i);
        }
    }

    int ans = 1e9;
    for(int rt = 1; rt <= n; rt++){

        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)adjT[i].clear();
        tot = 0;
        

        queue<int> q;

        q.push(rt);
        vis[rt] = 1;

        while(q.size()){
            int node = q.front();

            q.pop();

            for(int child : adj[node]){
                if(vis[child]) continue;

                adjT[node].push_back(child);
                vis[child] = 1;
                q.push(child);

            }
        }

        bool flag = 1;
        for(int i = 1; i <= n; i++) flag &= vis[i];

        if(!flag) continue;
        dfs(rt);
        ans = min(ans, tot);
    }

    cout << ans << "\n";
}
