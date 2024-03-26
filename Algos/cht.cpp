#include <bits/stdc++.h>
#include <iostream>

using namespace std;



const int MAXN = 2e5+5;
const long long INF = 1e18;




int n;

long long dp[MAXN],c,h[MAXN];

struct CHT {
    struct line {
        long long k, b;
        line() {}
        line(long long k, long long b): k(k), b(b) {}
        
        double intersect(line l) {
            double db = l.b - b;
            double dk = k - l.k;
            return db / dk;
        }
        
        long long operator () (long long x) {
            return k * x + b;
        }
    };
    
    vector<double> x;
    vector<line> ll;
    
    void init(line l) {
        x.push_back(-INF);
        ll.push_back(l);
    }
    
    void addLine(line l) {
        while (ll.size() >= 2 && l.intersect(ll[ll.size() - 2]) <= x.back()) {
            x.pop_back();
            ll.pop_back();
        }
        if (!ll.empty()) {
            x.push_back(l.intersect(ll.back()));
        }
        ll.push_back(l);
    }
    
    long long query(long long qx) {
        int id = upper_bound(x.begin(), x.end(), qx) - x.begin();
        --id;
        return ll[id](qx);
    }
};



int32_t main() {
  cin >> n >> c;

  for(int i = 1; i <= n; i++){
    cin >> h[i];
  }
  
  CHT cht;
  
  cht.init(CHT::line(0,0));

  for(int i = 1; i <= n; i++){
    if(i > 1){
      //cout << query(h[i]) << endl;
      
      dp[i] = cht.query(h[i]) + c + h[i] * h[i];
    }

    cht.addLine(CHT::line(-2*h[i],dp[i] + h[i] * h[i]));
  }

  cout << dp[n] << "\n";
}