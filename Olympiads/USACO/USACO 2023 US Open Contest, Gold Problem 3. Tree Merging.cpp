#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 1005;

int n,m, p[MAXN], deg[MAXN];

bool vis[MAXN];


vector<int> adj[MAXN], adj2[MAXN];

vector<pair<int,int>> ans;
/*
rooted tree
we can delete leaves 

both the root and max value must be present in the answer graph
*/



void dfs(int node){
    for(int child : adj[node]) dfs(child);
    for(int child : adj2[node]){

        if(p[child] != node && !vis[p[child]]){
            //annex the sibling

            ans.push_back({p[child], node});
            vis[p[child]] = 1;
        }   
    }
    
}
int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        ans.clear();
        for(int i = 1; i <= n; i++){
            p[i] = 0;
            deg[i] = 0;
            vis[i] = 0;
            adj[i].clear();
            adj2[i].clear();
        }

        for(int i = 1; i <= n -1; i++){
            int x,y; cin >> x >> y;

            p[x] = y;
            adj[y].push_back(x);
            deg[x]++;
        }

        int u;

        for(int i = 1; i <= n; i++){
            if(!deg[i]) u = i;
        }

        cin >> m;

        for(int i = 1; i <= m-1; i++){
            int x,y; cin >> x >> y;

            adj2[y].push_back(x);
        }

        dfs(u);

       
        cout << ans.size() << "\n";
        for(auto [a,b] : ans) cout << a << " " << b << "\n";

        if(ans.size() == 2 && ans[0] == make_pair(4,5)){
            cout << "FUCK YOU\n";
            cout << u << "\n";
            cout << n << "\n";

            for(int i = 1; i <= n; i++){
                cout << i << "\n";
                for(int child : adj[i]) cout << child << " ";
                cout << "\n";

            }

            cout << "\n";

            cout << m << "\n";

            for(int i = 1; i <= n; i++){
                cout << i << "\n";
                for(int child : adj2[i]) cout << child << ' ';
                cout << "\n";
            }

            cout << "\n";

            return 0;


        }




    }
}


