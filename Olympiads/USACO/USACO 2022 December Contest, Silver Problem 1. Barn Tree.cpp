#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const int MAXN = 2e5+5;

int n,ans;
ll target;

int bales[MAXN];
vector<int> adj[MAXN];
vector<int> f[MAXN];
vector<pll> t[MAXN];
bool visited[MAXN];


ll dfs(int node, int parent){
  ll extra = bales[node] - target;


  for(int child:adj[node]){
    if(child == parent)continue;
    ll cextra = dfs(child,node);
    extra += cextra;

    if(cextra>0){
      f[node].push_back(child);
      t[child].push_back(make_pair(node,cextra));
      ans++;
    }
    else if(cextra<0){
      f[child].push_back(node);
      t[node].push_back(make_pair(child,-cextra));
      ans ++;
    }
  }

  return extra;
}


void p(int node){
  visited[node] = 1;
  for(int child:f[node]){
    if(!visited[child]){
      p(child);
    }
  }

  for(pll i:t[node]){
    cout << node << " " << i.first << " " << i.second << "\n";
  }
}




int main() {

  cin.tie(0)->sync_with_stdio(0);
  cin >> n;

  
  ll tot = 0;
  for(int i = 1; i <= n; i++){
    cin >> bales[i];
    tot += bales[i];
  }

  for(int i = 1; i < n; i++){
    int x,y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  target = tot/n;

  




  dfs(1,0);
  cout << ans << "\n";
  for(int node = 1; node < n+1;node++){
    if(!visited[node]){
      p(node);
    }
  }
}