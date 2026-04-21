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

    while(tt--){
        cin >> n >> m >> K >> L;

        for(int i = 1; i <= n; i++){
            col[i] = 0;
            sink[i] = 0;
            adj[i].clear();
            dist[i] = -1;
            level[i].clear();
            spec[i] = 0;
            dp[i] = 0;
            dp2[i] = 0;
        }
        spec[0] = 0;

        for(int i = 1; i <= K; i++){
            int x; cin >> x;
            col[x]=1;
        }

        for(int i = 1;i <= L; i++){
            int x; cin >> x;
            sink[x] = 1;
        }

        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        queue<int> q;
        dist[1] = 0;
        int mx = 0;
        q.push(1);

        while(q.size()){
            int node = q.front();
            level[dist[node]].push_back(node);

            q.pop();

            for(int child : adj[node]){
                if(dist[child] == -1){
                    dist[child] = dist[node]+1;
                    q.push(child);
                }
            }
        }

        bool ans = 1;

        for(int i = n; i >= 1; i--){
            if(!level[i].size()) continue;

            
            for(int j : level[i]){
                
                if(sink[j]) dp[j] = 1;
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
                        if(dist[child] > dist[j]) continue;
                        dp[child] |= dp[j];
                    }
                }
            }

            else{
                for(int child : adj[spec[i]]){
                    if(dist[child] > dist[spec[i]]) continue;
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
            for(int j : level[i]){

                if(spec[i+1]) dp2[spec[i+1]] |= dp2[j];
                else{
                    for(int child : adj[j]){
                        if(dist[child] < dist[j]) continue;
                        dp2[child] |= dp2[j];
                    }
                }
            }
        }


        for(int i =2 ; i <= n; i++) cout << (dp[i]);
        cout << "\n";
        


        








    }
}