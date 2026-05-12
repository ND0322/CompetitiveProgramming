#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, m, cF, cS, dist[MAXN], nxt[MAXN];

bool dp[MAXN], dp2[MAXN];

set<int> adj[MAXN], level[MAXN];


bool col[MAXN], sink[MAXN];

/*
level by level
if two colored nodes thats bad 
one colored we go through there
no colored we choose next 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m >> cF >> cS;

        for(int i = 1; i <= n; i++){
            dist[i] = 0;
            nxt[i] = 0;
            dp[i] = 0;
            dp2[i] = 0;
            adj[i].clear();
            level[i].clear();
            col[i] = 0;
            sink[i] = 0;
        }

        for(int i = 1; i <= cF; i++){
            int x; cin >> x;

            col[x]= 1;
        }

        for(int i = 1; i <= cS; i++){
            int x; cin >> x;

            sink[x] = 1;
        }

        for(int i = 1; i <= m; i++){

            int x,y; cin >> x >> y;

            adj[x].insert(y);
            adj[y].insert(x);
        }



        queue<int> q;

        q.push(1);
        dist[1] = 1;

        int mx = -1;

        bool flag = 1;

        while(q.size()){
            int node = q.front();

            level[dist[node]].insert(node);
            mx = max(mx, dist[node]);

            q.pop();

            for(int child : adj[node]){
                if(dist[child]) continue;

                dist[child] = dist[node] + 1;
                if(col[child]){
                    flag &= !nxt[node];
                    nxt[node] = child;
                }
                q.push(child);
            }
        }



        if(!flag){
            for(int i = 2; i <= n; i++) cout << "0";
            cout << "\n";
            continue;
        }

        for(int i = 1; i <= n; i++){
            if(!col[i]) continue;

            for(int child : adj[i]){
                if(dist[child] < dist[i]) nxt[child] = i;
            }
        }

        int cap = 0;

        for(int i = 1; i <= n; i++){
            if(col[i]) cap = max(cap, dist[i]);
        }

        for(int i = mx; i >= 1; i--){
            for(int node : level[i]){
                dp[node] = (sink[node] && dist[node] >= cap);

                if(nxt[node]){
                    dp[node] |= nxt[node];
                    continue;
                }

                for(int child : adj[node]){
                    if(dist[child] > dist[node]) dp[node] |= dp[child];
                }
            }
        }

        dp2[1] = 1;

        for(int i = 1; i <= mx; i++){
            for(int node : level[i]){
                if(nxt[node]){
                    dp2[nxt[node]] |= dp2[node];
                    continue;
                }

                for(int child : adj[node]){
                    if(dist[child] > dist[node]) dp2[child] |= dp2[node];
                }
            }
        }

        for(int i = 2; i <= n; i++){
            cout << (dp2[i] && dp[i]);
        }

        cout << "\n";




        




    }
}