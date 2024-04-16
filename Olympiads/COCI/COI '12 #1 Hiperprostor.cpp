#include <bits/stdc++.h>
#include <iostream>
#include <queue>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;

const int MAXN = 505;
const int MAXM = 1e4+5;

int n, m, q, a,b, dist[MAXN][MAXM], dd[MAXN];

vector<pair<int,pair<bool, int>>> adj[MAXN];

/*
shortest path from a to b using x special edges
for all number of special edges
binary search for upper and lower bound of x where that number of things are on the shortest path
processing in decreasing order lower bound always increases
*/

int can(int x){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i = 1; i <= n; i++) dd[i] = 1e9;

    dd[a] = 0;

    pq.push({0,a});

    while(pq.size()){
        auto [d,node] = pq.top();

        pq.pop();
        
        for(auto c : adj[node]){
            int child = c.first;
            auto[id,weight] = c.second;

            if(dd[child] > d + weight + id*x){
                dd[child] = d+weight+id*x;
                pq.push({dd[child], child});
            }
        }
    }

    return dd[b];
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        string s; cin >> s;
        if(s == "x") adj[x].push_back({y, {1, 0}});
        else adj[x].push_back({y, {0, stoi(s)}});
      
    }

    cin >> q;

    while(q--){
        cin >> a >> b;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= m; j++) dist[i][j] = 1e9;
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        dist[a][0] = 0;
        pq.push({0, {a,0}});



        while(pq.size()){
            int d = pq.top().first;

            auto [node, cnt] = pq.top().second;

            pq.pop();

            for(auto c : adj[node]){
                int child = c.first;
                bool id = c.second.first;
                int weight = c.second.second;

                if(dist[child][cnt+id] > d + weight){
                    dist[child][cnt+id] = d+weight;
                    pq.push({d+weight, {child, cnt+id}});
                }
            }

        }

        if(can(0) == 1e9){
            cout << "0 0\n";
            continue;
        }

        if(dist[b][0] == 1e9){
            cout << "inf\n";
            continue;
        }

        

        int ans = 0;
        int cnt = 0;

        int last = 1;

        

        for(int i = m; i >= 1; i--){
            int hi = 1e9;
            int lo = last+1;

            int res = -1;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(can(mid) == dist[b][i] + i*mid){
                    res = mid;
                    lo = mid+1;
                }
                else hi = mid-1;
            }

            
            
            if(res < last){
                last = max(res+1, last);
                continue;
            }
            cnt += (res-last+1); 
            ans += dist[b][i] * (res-last+1);
            ans += i*((res + last) * (res-last+1))/2;  
            last = max(res+1, last);      
        }

       
       
        if(can(last-1) != dist[b][0] || last-1 == 0) cout << cnt+1 << " " << ans+dist[b][0] << "\n";
        else cout << cnt << " " << ans << "\n";
        
    



        

    }
}