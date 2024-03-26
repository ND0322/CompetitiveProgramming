#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

//old code is too bad to copy 

const int MAXN = 1e5+5;
const int INF = 1e9;

int dist[MAXN][2];

vector<pair<int,int>> adj[MAXN];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int travel_plan(int n, int m, int in[][2], int w[], int k, int e[]){

    for(int i = 0; i < m; i++){
        int x = in[i][0];
        int y = in[i][1];
        int c = w[i];

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    

    for(int i = 0; i <= n; i++) dist[i][0] = dist[i][1] = INF;

    for(int i = 0; i < k; i++){
        dist[e[i]][0] = 0;
        dist[e[i]][1] = 0;
        pq.push({0, e[i]});
    }

    while(pq.size()){
        int node = pq.top().second;
        int d = pq.top().first;

        pq.pop();

        if(d != dist[node][1]) continue;
       

        for(auto [child, weight] : adj[node]){
            if(dist[child][0] > d + weight){

                if(dist[child][0] != dist[child][1]){
                    dist[child][1] = dist[child][0];
                    pq.push({dist[child][1], child});
                }
                
                dist[child][0] = d + weight;
                
            }
            else if(dist[child][1] > d + weight){
                dist[child][1] = d+weight;
                pq.push({dist[child][1], child});
            }
        }
    }

    return dist[0][1];
}


int main(){
    int balls[4][2] = {{0,1}, {0,2}, {3,2}, {2,4}};
    int l[4] = {2,3,1,4};
    int ex[3] = {1,3,4};
    cout << travel_plan(5, 4, balls, l, 3, ex) << "\n";
}
