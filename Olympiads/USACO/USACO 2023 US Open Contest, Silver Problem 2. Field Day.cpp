#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

int main() {
  int c,n; cin >> c >> n;

  vector<int> teams(n,-1);
  vector<int> distances((1<<c),-1);
  queue<int> q;
  vector<bool> visited((1<<c),false);

  for(int i = 0;i<n;i++){
    string cows; cin >> cows;
    replace(cows.begin(), cows.end(), 'G', '1');
    replace(cows.begin(), cows.end(), 'H', '0');

    

    teams[i] = stoi(cows,0,2);


    distances[teams[i]] = 0;
    q.push(teams[i]);
    visited[teams[i]] = true;
  
  }


  

  while(!q.empty()){
    int node = q.front();

    q.pop();

    for(int i = 0;i<c;i++){
      int child = node^(1<<i);

      if(!visited[child]){
        visited[child] = true;
        distances[child] = distances[node] + 1;
        q.push(child);
      }
    }

    
  }

  for(int i = 0; i< n;i++){
    
    cout << c - distances[((1 << c)-1) ^ teams[i]] << endl;
  }

  
}