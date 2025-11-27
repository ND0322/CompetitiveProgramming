#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

const int MAXN = 4e5+5;

vector<pair<int,int>> adj[MAXN];

int n,m, ans[MAXN], deg[MAXN], deg2[MAXN][2];

pair<int,int> edges[MAXN];

bool vis[MAXN], vis2[MAXN];

vector<int> cur, path;



/*
explore odd and even degrees
explore cycles
explore nature of ans (does each node always have half colored 

number of odd degrees?
its seems we should mark from odd to even edges 
handshake lemma 
at most one node will have > ceil(deg/2) colored
any graph with some odd-even edges is possible
any graph with even number of edges is possible 

eularian path to color 
*/


void dfs1(int node){
    if(vis[node]) return;
    vis[node] = 1;
    if(deg[node] & 1) cur.push_back(node);
    for(auto [child, id] : adj[node]) dfs1(child);
}

void dfs2(int node) {
	while (!adj[node].empty()) {
		auto [child, id] = adj[node].back();
		adj[node].pop_back();
		if(vis2[id]) continue;
		vis2[id] = 1;
		dfs2(child);
        path.push_back(id);
	}
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cin >> n >> m;


        for(int i = 1; i <= n*2; i++){
            vis[i] = 0;
            deg[i] = 0;
            deg2[i][1] = 0;
            deg2[i][0] = 0;
            adj[i].clear();
        }

        for(int i = 1; i <= m*2; i++){
            vis2[i] = 0;
            edges[i] = {0,0};
            ans[i] = 0;
        }

        

        int cnt = 0;
        for(int i =1 ; i <= m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back({y, i});
            adj[y].push_back({x,i});
            deg[x]++;
            deg[y]++;
            edges[i] = {x,y};
        }

        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            
            dfs1(i);

            int s = i;

            for(int i = 0; i < cur.size(); i+=2){
                s = cur[i];
                adj[cur[i]].push_back({cur[i+1], ++cnt + m});
                adj[cur[i+1]].push_back({cur[i], cnt + m});
            }   

            
            dfs2(s);

           
            for(int i = 0; i < path.size(); i++){
                if(path[i] > m) continue;
                ans[path[i]] = i&1;
                deg2[edges[path[i]].first][i&1]++;
                deg2[edges[path[i]].second][i&1]++;
            }


            cur.clear();
            path.clear();
        }

        long long sm = 0;
        for(int i =1 ; i <= n; i++) sm += deg2[i][0] * deg2[i][0] + deg2[i][1] * deg2[i][1];
    
        cout << "Case #" << _ << ": " << sm << " ";

        for(int i = 1; i <= m; i++) cout << ans[i]+1;
        cout << "\n";
    }
}
