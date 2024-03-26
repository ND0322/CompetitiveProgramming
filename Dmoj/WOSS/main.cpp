#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

#define f first
#define s second

signed main(){
  ll n, m, k;
  cin >> n >> m >> k;

  vector<pair<ll, ll>> loc(1, {0, 0});
  vector<pair<ll, ll>> nex;

  int time = -1;

  for (int i = 0; i < m; i++){
    ll ai, bi, ti;
    cin >> ai >> bi >> ti;

    int diff = ti - time;
    time = ti;

    for (auto [l, r]: loc){
      ll nl = max(0LL, l - diff * k);
      ll nr = min(n, r + diff * k);

      cout << l << " " << r << " " << nl << " " << nr << "\n";

      while (!nex.empty() && nex.back().s >= nl){
        nl = min(nl, nex.back().f);
        nex.pop_back();
      }

      if (bi < nl || ai > nr) {
        nex.emplace_back(nl, nr);
        continue;
      }


      if (ai > nl){
        nex.emplace_back(nl, ai - 1);
      }

      if (bi < nr) {
        nex.emplace_back(bi + 1, nr);
      }

      /*
      if (ai <= nl) {
        if (bi < nr) {
          nex.emplace_back(bi, nr);
        }
      } else {
        
        if (bi < nr) {
          nex.emplace_back(bi, nr);
        }
      }*/
    }
    
    //for(auto [l,r] : nex) cout << l << " " << r << "\n";

    nex.swap(loc);
    nex.clear();
  }

  if (loc.empty()){
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}