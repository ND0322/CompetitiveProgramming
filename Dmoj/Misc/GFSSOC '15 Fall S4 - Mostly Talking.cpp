#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 5e5+5;
const long long INF = 1e10;


typedef long long ll;

typedef pair<ll,pair<int,bool>> tu;






int n,m,d;

ll distances[MAXN][2];

vector<pair<int,pair<ll,bool>>> adj[MAXN];

//ill try dp again
//if dosnt work i think i have another approach


int main() {
  cin >> n >> m;

 

  for(int i = 0; i < m; i++){
    int x,y,c; cin >> x >> y >> c;


    adj[x].push_back({y,{c,0}});
    
    
  }

  cin >> d;

  for(int i = 0; i < d; i++){
    int x,y,c; cin >>x >> y >> c;

    //cout << x << " "<< y<< " "<<c<<endl;

    adj[x].push_back({y,{c,1}});
    
  }

  for(int i = 1; i <= n; i++){
    distances[i][0] = distances[i][1] = INF;
  }

  priority_queue<tu,vector<tu>,greater<tu>> pq;
  distances[1][1] = 0;
  pq.push({0,{1,1}});

  while(!pq.empty()){
    int node = pq.top().second.first;
    ll d = pq.top().first;
    bool can = pq.top().second.second;

    pq.pop();

    if(d != distances[node][can]) continue;

    for(pair<int,pair<ll,bool>> i:adj[node]){
        int child = i.first;
        ll weight = i.second.first;
        bool type = i.second.second;

        if(!type){
            if(distances[child][can] > d + weight){
                distances[child][can] = d+weight;

                pq.push({d+weight,{child,can}});
            }
        }
        else{
            if(!can) continue;
            if(distances[child][0] > d + weight){
                distances[child][0] = d + weight;

                pq.push({d+weight,{child,0}});
            }
        }
    }
  }

  ll ans = min(distances[n][0],distances[n][1]);

  cout << (ans == INF ? -1 : ans) << "\n";
  




    


  
}

