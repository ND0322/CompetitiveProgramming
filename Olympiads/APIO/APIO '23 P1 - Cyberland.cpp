#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;




typedef pair<int,int> pii;
typedef tuple<double,int,int> tu;
int parents[100005];




const double INF = DBL_MAX;

int find(int x){
  int i = x; 
  while(i != parents[i]){
    parents[i] = parents[parents[i]];
    i = parents[i];
  }
  return i;
}

void Union(int x,int y){
  parents[find(x)] = find(y);
}



double solve(int N, int M, int K, int H, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr){
  vector<pii> adj[N];

  K = min(K,70);

for(int i = 0; i < N; i++){
  parents[i] = i;
}

  for(int i = 0; i < M; i++){
    if(x[i] != H && y[i] != H){
      if(find(x[i]) != find(y[i]))Union(x[i],y[i]);
      
    }
    adj[x[i]].push_back({y[i],c[i]});
    adj[y[i]].push_back({x[i],c[i]});
  }

  
  priority_queue<tu,vector<tu>,greater<tu>> pq;

  vector<vector<double>>distances(N,vector<double>(K+1,INF));
  

  //dfs(0,arr,K,H,adj);

  vector<double> twos(K + 1, 1);
  for(int i = 1; i <= K; i++){
    twos[i] = twos[i-1]/2;
  }

  arr[0] = 0;
  pq.push({0.0,K,H});
  distances[H][K] = 0.0;




  while(!pq.empty()){
    double d= get<0>(pq.top());
    int node = get<2>(pq.top());
    int k = get<1>(pq.top());

    pq.pop();

    /*
    if(node == H){
      continue;
    }
    */

    //d != distances[node][k] || 

    if (distances[node][k] < d)
			continue;

    if(!arr[node]){
      return d;
    }

    for(pii c: adj[node]){
      int child = c.first;
      int weight = c.second;

      if(find(child) != find(0)){
        continue;
      }

      

      if(arr[node] == 2){
        if(k && distances[child][k-1] > d + weight * twos[K-k+1]){
          
          distances[child][k-1] = d + weight * twos[K-k+1];
          pq.push({distances[child][k-1],k-1,child});
        }
      }
     
      if (distances[child][k] > d + weight * twos[K-k]){
        
        distances[child][k] = d + weight*twos[K-k];
        pq.push({distances[child][k],k,child});
      }
      
      
    }
    
  }

  return -1;

  

  

  
  
  
}


int main() {

  
  //Final solution: we divide by 2 whenever we can and we start from the end node. Dsu to see if child nodes can reach node 0, and stop when seeing a node with arr[v] == 0 because reverse
  

 
}