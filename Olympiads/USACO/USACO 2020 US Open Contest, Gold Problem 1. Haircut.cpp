#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;

typedef long long ll;
int main() {

  freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);

  
  int n; cin >> n;

  vector<int> hairs(n+1);

  for(int i = 0; i < n; i++){
    cin >> hairs[i];
  }

  vector<ll> psa(n+2);
  vector<vector<int>> mat(n+1,vector<int>());

  ost t;

  for(int i = 0; i < n;i++){
    mat[hairs[i]].push_back(i);
  }

  for(int i = n;i>-1;i--){
    for(int j:mat[i]){
      psa[i+1] += t.order_of_key(j); 
    }
    for(int j:mat[i]){
      t.insert(j);
    }
  }

  for(int i = 1; i < n;i++){
    psa[i] += psa[i-1];
  }

  cout << 0 << "\n";
  for(int i = 1; i < n;i++){
    cout << psa[i] << "\n";
  }
  
}