#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1005;
const long long INF = 1e18;

typedef pair<long long, int> pii;
typedef pair<pii,bool> help;

int n,a,b,c;

long long di[MAXN][MAXN], distances[MAXN][2];

int main(){
    cin >> n >> a >> b >> c;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> di[i][j];
        }
    }

    

    priority_queue<help, vector<help>, greater<help>> pq;

    for(int i = 0; i < n; i++){
        distances[i][0] = INF;
        distances[i][1] = INF;
    }

    distances[0][1] = 0;
    pq.push({{0,0}, 1});

    while(!pq.empty()){
        long long d = pq.top().first.first;
        int node = pq.top().first.second;
        bool can = pq.top().second;

        //cout << node << " " << d << " " << can << "\n";

        pq.pop();

        if(can){
            if(distances[node][0] > d){
                distances[node][0] = d;
                pq.push({{d,node}, 0});
            }
        }

        for(int child = 0; child < n; child++){
            if(node == child) continue;

            if(can){
                if(distances[child][1] > d + di[node][child] * a){
                    distances[child][1] = d + di[node][child] * a;

                    pq.push({{distances[child][1], child}, 1});
                }
            }
            else{
                if(distances[child][0] > d + di[node][child] * b + c){
                    distances[child][0] = d + di[node][child] * b + c;

                    pq.push({{distances[child][0], child}, 0});
                }
            }
        }
    }

    cout << min(distances[n-1][0], distances[n-1][1]) << "\n";
    
}

