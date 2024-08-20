#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

const int MAXN = 3005;

int n, m, k;

vector<int> adj[MAXN];
bool vis[MAXN][MAXN];

pair<int,int> last[MAXN][MAXN];

int main(){
    cin >> n >> m >> k;

    set<pair<pair<int,int>,int>> bad;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= k; i++){
        int x,y,z; cin >>x>>y>>z;

        bad.insert({{x,y}, z});
    }

    queue<pair<int,int>> q;
    vis[0][1] = 1;
    q.push({0,1});

    while(q.size()){
        auto [par, node] = q.front();

        q.pop();

        if(node == n){
            vector<int> ans;

            while(node != 1){
                //cout << par << " " << node << "\n";
                ans.push_back(node);
                pair<int,int> pr = last[par][node];
                par = pr.first;
                node = pr.second;
            }

            cout << ans.size() << "\n";

            reverse(ans.begin(), ans.end());
            cout << "1 ";
            for(int i : ans) cout << i << " ";
            cout << "\n";
            return 0;
        }

        for(int child : adj[node]){
            if(vis[node][child]) continue;
            if(bad.find({{par, node}, child}) != bad.end()) continue;
            last[node][child] = {par, node};
            vis[node][child] = 1;
            q.push({node, child});
        } 
    }

    cout << "-1\n";
}