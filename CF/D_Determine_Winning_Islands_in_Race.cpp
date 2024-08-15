#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

int n, m, d[MAXN];

vector<int> adj[MAXN];

/*
for each s we have to find a path using only the first s-1 edges 
we have the find the max of highest node we can jump to - time it takes to jump there
this value must be > s
im gonna used scuffed dijkstras cause bfs is giving me a stroek
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            adj[i].clear();
            if(i<n)adj[i].push_back(i+1);
            d[i] = 1e9;
        }
        for(int i = 0; i < m; i++){
            int x,y; cin >> x >> y;
            if(x > y) swap(x,y);

            adj[x].push_back(y);
        }

        
        int jmp = 0;
        d[1] = 0;

        for(int i = 1; i < n; i++){
            //for all children propagate as di + 1

            for(int child : adj[i-1]){
                if(d[child] > d[i-1] + 1){
                    d[child] = d[i-1]+1;
                    jmp = max(jmp, child - d[child]);
                }
            }

            //cout << i << " " << jmp << "\n";
            cout << (jmp <= i);
        }

        cout << "\n";
    }
}