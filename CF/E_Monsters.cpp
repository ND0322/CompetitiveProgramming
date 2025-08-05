#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

vector<int> adj[MAXN];
int a[MAXN], cnt[MAXN], sz[MAXN], parents[MAXN];
set<pair<int,int>> pq[MAXN];


/*
Consider propagating from all source nodes
Connect colored ccs when we can

keep a prio queue of neighbors we cannot yet visit 

attempt to start from each source and if we fail just book mark it and keep its info
use dsu dumbass 
*/

int find(int node){
    return (parents[node] == node ? node : parents[node] = find(parents[node]));
}

bool uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return 0;

    if(sz[x] < sz[y]) swap(x,y);
    if(pq[x].size() < pq[y].size()) pq[x].swap(pq[y]);
    for(auto i : pq[y]) pq[x].insert(i);
    parents[y] = x;
    sz[x] += sz[y];
    return 1;

}

int main(){
    int tt; cin >> tt;



    while(tt--){
        int n, m; cin >> n >> m;





        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sz[i] = 1;
            parents[i] = i;
            pq[i] = {{0, i}};
            adj[i].clear();
           

        }


        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);

        }

        for(int i = 1; i <= n; i++){
            if(a[i]) continue;


            while(pq[find(i)].size() && (*pq[find(i)].begin()).first <= sz[find(i)]){
                auto [x, node] = *pq[find(i)].begin();

                pq[find(i)].erase({x,node});                

                for(int child : adj[node]){


                    if(a[child] < sz[find(i)]) uni(node, child);
                    else pq[find(i)].insert({a[child], child});
                    
                }


            }
        }

        cout << (sz[find(1)] == n ? "YES\n" : "NO\n");



      


    }
}