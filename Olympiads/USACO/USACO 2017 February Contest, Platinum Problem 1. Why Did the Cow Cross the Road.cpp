#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>



using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;
typedef long long ll;

const int MAXN = 1e5+5;

int n, q[2][MAXN], qInv[2][MAXN], qCopy[2][MAXN];

ost t;

vector<int> merged;

ll inversions(int p[], int l, int r) {
    if (l != r) {
        int m = (l+r) / 2;  // [l,m], [m+1,r]

        ll res = inversions(p, l, m) + inversions(p, m + 1, r);

        merged.clear();

        int i = l; int j = m + 1;

        while (i <= m && j <= r) {
            if (p[i] < p[j]) {
                res += j - (m + 1);
                merged.push_back(p[i]);
                i++;
            }
            else {
                merged.push_back(p[j]);
                j++;
            }
        }
        while (i <= m) {
            res += j - (m + 1);
            merged.push_back(p[i]);
            i++;
        }
        while (j <= r) {
            merged.push_back(p[j]);
            j++;
        }

        i = 0;
        for (j = l; j <= r; j++) {
            p[j] = merged[i];
            i++;
        }

        return res;
    }
    else {
        return 0;
    }
}

ll inv(int p[]){

  
  int cnt = 0;

  for(int i = n-1; i >= 0; i--){
    cnt += t.order_of_key(p[i]);

    

    t.insert(p[i]);
    
  }

  return cnt;
}


int main() {

  freopen("mincross.in","r",stdin);
  freopen("mincross.out","w",stdout);
  cin >> n;

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < n; j++){
      cin >> q[i][j];
      qInv[i][q[i][j]] = j+1;
    }
  } 

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < n; j++){
      qCopy[i][j] = qInv[1-i][q[i][j]];
    }
  }

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < n; j++){
      q[i][j] = qCopy[i][j];
    }
  }

  
  

  

  
    

    
  ll ans = LLONG_MAX;

  for(int i = 0; i < 2; i++){
    ll cur = inversions(q[i], 0, n-1);

    //cout << "r " << cur << "\n";

    

    for(int j = n-1; j >= 0; j--){
      //cout << qCopy[i][j] << "\n";
      cur += 2*qCopy[i][j]-n-1;
      ans = min(ans,cur);
    }
    
  }

  cout << ans << "\n";

  
}