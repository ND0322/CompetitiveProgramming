#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e4+5;

int n, k, col[MAXN], dist[MAXN][3];

bool edge[55][55];

set<int> nodes[55];

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> col[i];
        nodes[col[i]].insert(i);
    }

    for(int i = 1; i <= k; i++){
        string s; cin >> s;

        for(int j = 1; j <= k; j++) edge[i][j] = s[j-1] == '1';
    }

    for(int i = 1; i <= n; i++)dist[i][0] = dist[i][1] = dist[i][2] = 1e9;

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    dist[1][0] = 0;
    pq.push({0, {1,0}});


    //maybe need to from easch child calculate the closest parent 
    while(pq.size()){
        int d = pq.top().first;
        auto [node, dir] = pq.top().second;
        pq.pop();

        for(int i = 1; i <= k; i++){
            if(!edge[col[node]][i]) continue;


            auto it = nodes[i].lower_bound(node);

            if(it != nodes[i].end()){
                if(dist[*it][2] > d + *it - node){
                    dist[*it][2] = d + *it - node;
                    pq.push({dist[*it][2], {*it, 2}});
                }
            }

            if(it != nodes[i].begin()){
                it--;

                if(dist[*it][1] > d + node - *it){
                    dist[*it][1] = d + node - *it;
                    pq.push({dist[*it][1], {*it, 1}});
                }
            }
        }

        if(dir == 2){
            auto it = nodes[col[node]].find(node);
            it++;

            if(it != nodes[col[node]].end()){
                if(dist[*it][2] > d + *it - node){
                    dist[*it][2] = d + *it - node;
                    pq.push({dist[*it][2], {*it, 2}});
                }
            }
        }

        if(dir == 1){
            auto it = nodes[col[node]].find(node);
            if(it != nodes[col[node]].begin()){
                it--;
                if(dist[*it][1] > d + node - *it){
                    dist[*it][1] = d + node - *it;
                    pq.push({dist[*it][1], {*it, 1}});
                }
            }
        }

        if(dist[node][0] > d){
            dist[node][0] = d;
            pq.push({dist[node][0], {node, 0}});
        }
    }

    cout << dist[n][0] << "\n";

    

}