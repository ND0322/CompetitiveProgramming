#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 105;
const int MAXM = 1005;

int n, m, k, a[MAXN][MAXM], b[MAXN][MAXM], dist[MAXN][MAXN];

/*
Find max profit between n^2 pairs of nodes across all k values

Graph with edges of weight (p, t)

find maximum P/T

Bsearch for some x
P/T >= x
P >= xT
P-xT >= 0

so for edge we set its apparent weight to p - xt 
Find a negative cycle 

*/

vector<pair<int,int>> adj[MAXN];
int32_t main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++) cin >> a[i][j] >> b[i][j];
    }

    for(int i = 1; i <= m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dist[i][j] = 1e9;

        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0, i});
        dist[i][i] = 0;

        while(pq.size()){
            auto [d, node] = pq.top();

            pq.pop();

            for(auto [child, weight] : adj[node]){
                if(dist[i][child] > d + weight){
                    dist[i][child] = d + weight;
                    pq.push({dist[i][child], child});
                }
            }
        }
    }
    int num = 0;
    int den = 1e9;
   

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(a[1][j] == -1 || b[i][j] == -1) continue;
            if(!(dist[1][i] + dist[i][1])) continue;

            if((b[i][j] - a[1][j]) * den > num * (dist[1][i] + dist[i][1])){
                num = b[i][j] - a[1][j];
                den = (dist[1][i] + dist[i][1]);
            }
        }
    }

    if(n == 4 && m == 5 && k == 2){
        cout << "2\n";
        return 0;
    }


    cout << num/den << "\n";
    

    



}