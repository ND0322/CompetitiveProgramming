#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e4+5;

int n, k;

bool vis[MAXN];

bitset<MAXN> has[MAXN];

int deg[MAXN];

set<int> adj[MAXN];

//find a clique given for every node that the min degree <= k
/*
graph must contain some node with degree <= k

find smallest node
find all cliques containing this node and neighbors
remove this node and move to neighbors

Now we can consider all cliques that werent already counted by the parent node
*/

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        while(x--){
            int y; cin >> y;
            y++;

            deg[i]++;

            adj[i].insert(y);
            has[i][y] = 1;
        }
    }


    set<pair<int,int>> s;

    for(int i = 1; i <= n; i++) s.insert({deg[i], i});

    int ans =0 ;
    while(s.size()){
        auto [d, node] = *s.begin();

        s.erase(s.begin());

        if(d > k) break;
        if(d > deg[node]) continue;



        int sz = adj[node].size();
        vector<int> tmp;

        for(int i : adj[node]) tmp.push_back(i);
        for(int i = 0; i < 1<<sz; i++){

            vector<int> clique;
            for(int j = 0; j < sz; j++){
                if(i & (1<<j)) clique.push_back(tmp[j]);
            }

            bool flag = 1;
            for(int j : clique){
                for(int p : clique){
                    if(j == p) continue;

                    flag &= has[j][p];
                }
            }

            if(flag) ans = max(ans, (int)clique.size()+1);
        }

        for(int child : adj[node]){
            s.erase({deg[child], child});
            deg[child]--;
            adj[child].erase(node);
            s.insert({deg[child], child});
            
        }
    }  

    cout << ans << "\n";
}