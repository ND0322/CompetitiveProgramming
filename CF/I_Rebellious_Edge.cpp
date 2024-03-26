#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<long long,int> pii;
const int MAXN = 2e5+5;
const int MAXM = 5e5+5;
const long long INF = 1e18;

int n, m, up[MAXN],id;

long long dist[MAXN];

vector<pair<int,pair<int,int>>> adj[MAXN];

vector<pair<pii,pair<int,int>>> adjrev[MAXN];

pair<pair<int,int>,int> a[MAXM];

bool done[MAXN];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        int in, out;

        for(int i = 1; i <= n; i++){
            adj[i].clear();
            done[i] = 0;
            adjrev[i].clear();
            
        }


        for(int i = 0; i < m; i++){
            int x,y,c; cin >> x >> y >> c;

            a[i] = {{x,y},c};

            if(y < x){
                id = i;
                in = x;
                out = y;
            }

            adj[x].push_back({y,{c,i}});
            adjrev[y].push_back({{x,adj[x].size()-1},{c,i}});
        }

        for(int i = 1; i <= n; i++) dist[i] = INF;
        
        

        priority_queue<pii,vector<pii>,greater<pii>> pq;

        dist[1] = 0;
        pq.push({0,1});

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
           

            pq.pop();

            for(auto c : adj[node]){
                int child = c.first;
                auto [weight, ind] = c.second;

                if(ind == id) continue;

                if(dist[child] > d + weight){
                    dist[child] = d + weight;

                    up[child] = ind;

                    pq.push({d + weight, child});
                }

                
            }
        }

        long long ans = 0;

        for(int i = 2; i <= n; i++) ans += a[up[i]].second;

        long long res = 0;

        for(int i = 1; i <= n; i++){
            if(i == 1 || i == out) continue;

            int balls = 1e9;

            for(auto c : adjrev[i]) balls = min(balls, c.second.first);
            for(auto c : adjrev[i]) adj[c.first.first][c.first.second].second.first -= balls;
            res += balls;
        }

        for(int i = 1; i <= n; i++) dist[i] = INF;

        dist[1] = 0;
        pq.push({0,1});

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
           

            pq.pop();

            for(auto c : adj[node]){
                int child = c.first;
                auto [weight, ind] = c.second;

                if(ind == id) continue;

                if(dist[child] > d + weight){
                    dist[child] = d + weight;

                    up[child] = ind;

                    pq.push({d + weight, child});
                }

                
            }
        }

        int cur = in;

        while(cur != 1){
            res += a[up[cur]].second;
            done[cur] = 1;

            cur = a[up[cur]].first.first;
        }

        done[1] = 1;

        for(int i = 1; i <= n; i++){
            if(!done[i]){
                int balls = 1e9;

                for(auto c : adjrev[i]) balls = min(balls, c.second.first);

                res += balls;

                
            }
        }

        cout << min(ans, res) << "\n";

        
            
        
        




    }
}