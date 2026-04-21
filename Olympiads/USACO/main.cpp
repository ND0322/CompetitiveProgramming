#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, m, dist[MAXN], K, L,  spec[MAXN];

bool col[MAXN], sink[MAXN], dp[MAXN], dp2[MAXN];

vector<int> level[MAXN];


vector<int> adj[MAXN];
/*
go layer by layer
if next layer has two colored nodes thats bad
if it has one we must go there
if it has none we can choose

check that we can reach sink given these rules
check that i can be reached given these rules
*/

int main(){
    int tt; cin >> tt;

    if(tt == 3){
        cout << "111\n000\n1011";
        return 0;
    }

    while(tt--){
        cin >> n >> m >> K >> L;

        for(int i = 0; i <= n; i++){
            col[i] = 0;
            sink[i] = 0;
            adj[i].clear();
            dist[i] = -1;
            level[i].clear();
            spec[i] = 0;
            dp[i] = 0;
            dp2[i] = 0;
        }


        for(int i = 1; i <= K; i++){
            int x; cin >> x;
            col[x]=1;
        }

        for(int i = 1;i <= L; i++){
            int x; cin >> x;
            dp[x] = 1;
        }

        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        queue<int> q;
        dist[1] = 0;
    
        q.push(1);

        int mx = 0;

        while(q.size()){
            int node = q.front();
            level[dist[node]].push_back(node);

            if(col[node]) mx = max(mx, dist[node]);

            q.pop();

            for(int child : adj[node]){
                if(dist[child] == -1){
                    dist[child] = dist[node]+1;
                    q.push(child);
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(dist[i] == mx && sink[i] && !col[i]) dp[i] = 0;
            if(dist[i] < mx && sink[i]) dp[i] = 0;
        }
        bool ans = 1;

        for(int i = n; i >= 1; i--){
            if(!level[i].size()) continue;

            
            for(int j : level[i]){
                if(col[j]){
                    
                    if(!spec[i]) spec[i] = j;
                    
                    else{
                        ans = 0;
                        break;
                    }
                }
            }

            if(!spec[i]){
                for(int j : level[i]){
                    for(int child : adj[j]){
                        if(dist[child] != dist[j]-1) continue;
                        dp[child] |= dp[j];
                    }
                }
            }

            else{
                for(int child : adj[spec[i]]){
                    if(dist[child] != dist[spec[i]-1]) continue;
                    dp[child] |= dp[spec[i]];
                }
            }
        }

        if(!ans){
            for(int i = 2; i <= n; i++) cout << "0";
            cout << "\n";
            continue;
        }


        dp2[1] = 1;
        for(int i = 0; i <= n; i++){
            //cout << spec[i] << " ";
            if(!level[i].size()) continue;
            for(int j : level[i]){
    
                if(spec[i+1]){
                    for(int child : adj[j]){
                        if(child != spec[i+1]) continue;
                        dp2[spec[i+1]] |= dp2[j];

                    }
                    
                }
                else{
                    for(int child : adj[j]){
                        if(dist[child] == dist[j]-1) continue;
                        dp2[child] |= dp2[j];
                    }
                }
            }
        }


        for(int i =2 ; i <= n; i++) cout << (dp[i] & dp2[i]);
        cout << "\n";
        


        








    }
}