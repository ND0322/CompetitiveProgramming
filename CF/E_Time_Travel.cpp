#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;
const int INF = 1e9;

typedef pair<int,int> pii;

int n, k, t, distances[MAXN];

vector<pii> adj[MAXN];
vector<int> times[MAXN];

int main(){
    cin >> n >> t;

    for(int i = 1; i <= t; i++){
        int m; cin >> m;

        for(int j = 0; j < m; j++){
            int x,y; cin >> x >> y;

            adj[x].push_back({y,i});
            adj[y].push_back({x,i});
        }
    }

    cin >> k;

    for(int i = 1; i <= k; i++){
        int x; cin >> x;

        times[x].push_back(i);
        
    }

    priority_queue<pii,vector<pii>,greater<pii>> pq;

    fill(distances, distances+n+1, INF);

    distances[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(d != distances[node]) continue;


        for(pii c : adj[node]){
            int child = c.first;
            int i = c.second;

            vector<int>::iterator it;

            it = upper_bound(times[i].begin(), times[i].end(), d);


            //doesnt exist
            if(it == times[i].end()) continue;

            if(distances[child] > *it){
                distances[child] = *it;
                pq.push({*it, child});
            }
        }

    }

    cout << (distances[n] == INF ? -1 : distances[n]) << "\n";
}