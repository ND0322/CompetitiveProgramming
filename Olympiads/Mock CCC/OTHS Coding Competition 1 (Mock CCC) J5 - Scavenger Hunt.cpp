#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e4+5;

#define int long long

typedef pair<int,int> pii;

int n,m, k, dist[MAXN][35], a[35], cnt[35];

bool has[MAXN][35];

vector<pii> adj[MAXN];
priority_queue<pair<int,pii>, vector<pair<int,pii>>,greater<pair<int,pii>>> pq;



int32_t main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= k; i++) cin >> a[i];

    for(int i = 1; i <= k; i++) cin >> cnt[i];

    for(int i = 1; i <= k; i++){
        for(int j = 0; j < cnt[i]; j++){
            int x; cin >> x;

            has[x][i] = 1;
        }
    }



    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k+1; j++) dist[i][j] = 1e18;
    }
    dist[1][1] = 0;
    pq.push({0,{1,1}});

    while(!pq.empty()){
        int node = pq.top().second.first;
        int d = pq.top().first;
        int cur = pq.top().second.second;

        pq.pop();


        if(cur > k) continue;

        

        if(dist[node][cur+1] > d + a[cur]){
            dist[node][cur+1] = d + a[cur];
            pq.push({dist[node][cur+1], {node,cur+1}});
        }

        if(has[node][cur] && dist[node][cur+1] > d){
            dist[node][cur+1] = d;

            pq.push({dist[node][cur+1], {node,cur+1}});
        }

        for(auto [child, weight] : adj[node]){
            if(dist[child][cur + has[child][cur]] > d + weight){

                dist[child][cur + has[child][cur]] = d + weight;
                pq.push({dist[child][cur + has[child][cur]], {child, cur + has[child][cur]}});
            }
        }
    }


    int ans = 1e18;

    for(int i = 1; i <= n; i++) ans = min(ans, dist[i][k+1]);

    cout << ans << "\n";


}