#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2005;



int n, m, v1, v2, tin[MAXN], dist[MAXN];

vector<pair<int,int>> adj[MAXN];


vector<pair<pair<int,int>, int>> edges;

/*
maxmimum minimum over all paths
2 dijkstras 

First dijkstra to find when nodes get blocked off
second dijkstra to find shortest path to possible nodes given the blocked off times
Calculate all node answers
*/

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

int32_t main(){
    cin >> n >> m >> v1 >> v2;

    for(int i = 1; i <= m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
        edges.push_back({{x,y}, c});
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            tin[j] = 1e9;
            dist[j] = 1e9;
        }

        tin[i] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, i});

        while(pq.size()){
            auto [d,node] = pq.top();

            pq.pop();

            for(auto [child, weight] : adj[node]){
                if(tin[child] > d + weight){
                    tin[child] = d + weight;
                    pq.push({tin[child], child});
                }
            }
        }

        dist[1] = 0;


        pq.push({0, 1});

        while(pq.size()){
            auto [d,node] = pq.top();

            pq.pop();

            if(tin[node] * v1 < d * v2) continue;

            for(auto [child, weight] : adj[node]){
                if(tin[child] * v1 <= (d+weight) * v2) continue;
                if(dist[child] > d + weight){
                    dist[child] = d + weight;
                    pq.push({dist[child], child});
                }
            }
        }

        int best = 0;
        int div = 1e9;

        for(int j = 1; j <= n; j++){
            if(dist[j] == 1e9) continue;
            if(best * v2 < tin[j] * div){
                best = tin[j];
                div = v2;
            }
        }


        for(auto e : edges){
            auto [x,y] = e.first;
            int d = e.second;

            if(dist[x] == 1e9 && dist[y] == 1e9) continue;

            if(dist[x] != 1e9){
                int val1 = (tin[x] - dist[x]);

                int tmp1 = (v2 - v1);


                if(v1 >= v2){
                    val1 = tin[x] + d + tin[y];
                    tmp1 = 2*v2;
                }


                int val2 = (dist[x] + tin[y] + d);
                int tmp2 = (v2 + v1);

                if(v1 >= v2){
                    val2 = 1e9;
                    tmp2 = 0;
                }
                else{
                    if(val2 * 2 * v2 < (tin[x] + d + tin[y]) * tmp2){
                        val2 = tin[x] + d + tin[y];
                        tmp2 = 2 * v2;
                    }
                }
                


                /*
                two edge cases
                v1 > v2
                Dist 1 should be the edge length
                time would be (tin[x] + d) / v2

                other edge case tin[y] = tin[x] + d
                time from y is effectively infinite

                */
                if(val1 * tmp2 < val2 * tmp1){
                    if(best * tmp1 < val1 * div){
                        best = val1;
                        div = tmp1;
                    }
                }
                else{
                    if(best * tmp2 < val2*div){
                        best = val2;
                        div = tmp2;
                    }
                }

            }

            
            swap(x,y);

            if(dist[x] != 1e9){
                int val1 = (tin[x] - dist[x]);

                int tmp1 = (v2 - v1);


                if(v1 >= v2){
                    val1 = tin[x] + d + tin[y];
                    tmp1 = 2*v2;
                }


                int val2 = (dist[x] + tin[y] + d);
                int tmp2 = (v2 + v1);

                if(v1 >= v2){
                    val2 = 1e9;
                    tmp2 = 0;
                }
                else{
                    if(val2 * 2 * v2 < (tin[x] + d + tin[y]) * tmp2){
                        val2 = tin[x] + d + tin[y];
                        tmp2 = 2 * v2;
                    }
                }
                


                /*
                two edge cases
                v1 > v2
                Dist 1 should be the edge length
                time would be (tin[x] + d) / v2

                other edge case tin[y] = tin[x] + d
                time from y is effectively infinite

                */
                if(val1 * tmp2 < val2 * tmp1){
                    if(best * tmp1 < val1 * div){
                        best = val1;
                        div = tmp1;
                    }
                }
                else{
                    if(best * tmp2 < val2*div){
                        best = val2;
                        div = tmp2;
                    }
                }

            }
        }




        cout << best / gcd(best, div) << "/" << div / gcd(best,div) << "\n";
     





    }
}

/*






*/