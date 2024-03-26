#include <bits/stdc++.h>
#include<iostream>
#include <stack>

using namespace std;

const int MAXN = 5e5+5;



int n,m,s,p,sums[MAXN],components[MAXN],dp[MAXN],disc[MAXN],low[MAXN],t,cnt;
int16_t val[MAXN];
//use val and sums as same thing

stack<int> st;
vector<int> adj[MAXN],adjScc[MAXN - 420000];
bitset<MAXN> visited,in,pubs;




void dfs(int node){
  disc[node] = low[node] = t++;
  st.push(node);
  in[node] = true;

  for(int child:adj[node]){
    if(!disc[child]){
      dfs(child);

      low[node] = min(low[node],low[child]);

      
    }
    else if(in[child]){
      low[node] = min(low[node],disc[child]);
    }
  }

  if(low[node] == disc[node]){
    while(st.top() != node){
      
      components[st.top()] = cnt;
      in[st.top()] = false;
      sums[cnt] += val[st.top()];

      st.pop();
      
    }

    components[st.top()] = cnt;
    in[st.top()] = false;

    sums[cnt] += val[st.top()];

    st.pop();

    cnt++;
  }

  
}


//reversing the graph takes too much time and memory
void dfs2(int node){
  for(int child:adjScc[node]){
    if(!dp[child]) dfs2(child);

    dp[node] = max(dp[node],dp[child]);
  }

  if(dp[node] || pubs[node]) dp[node] += sums[node];
}


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //this question makes me angry now i have to use tarjans
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int x,y; cin >> x >> y;

    adj[x].push_back(y);
   
  }

  for(int i = 1; i <= n; i++){
    cin >> val[i];
  }

  cin >> s >> p;

  


  for(int i = 1;i <= n; i++){
    if(!disc[i]){
      dfs(i);
    }
  }



  for(int node = 1; node <= n; node++){

  
    for(auto &child:adj[node]){
      if(components[node] != components[child]){
        adjScc[components[node]].push_back(components[child]);

        
      }
      
    }

    adj[node].clear();

  }

  for(int i = 0; i < p; i++){
    int x; cin >> x;
    pubs[components[x]] = true;
  }

  dfs2(components[s]);

  cout << dp[components[s]] << "\n";

  /*

  for(int i = 0; i < cnt; i++){
    cout << i << " " << sums[i] << endl;

    for(int child:adjScc[i]){
      cout << child << " ";
    }

    cout << endl;
  }

  */

  

  

  

  


  
}