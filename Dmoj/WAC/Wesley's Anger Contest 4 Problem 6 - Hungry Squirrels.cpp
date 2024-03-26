#include <bits/stdc++.h>
#include <iostream>
#include <queue>


typedef long long ll;


 
 
using namespace std;
 
const int MAXN = 2000;
const int MAXM = 5e5+5;
const ll INF = 1e18;

 
int n, m, cnt = 1, s, t,  tmp[505][505];

ll a[MAXN], sum; 

template <class _FlowUnit> struct FlowEdge {
  using FlowUnit = _FlowUnit; int to, rev; FlowUnit cap, resCap;
  FlowEdge(int to, int rev, FlowUnit cap)
      : to(to), rev(rev), cap(cap), resCap(cap) {}
};

template <class Edge> struct PushRelabelMaxFlow {
  using FlowUnit = typename Edge::FlowUnit;
  int V; FlowUnit FLOW_EPS; vector<vector<Edge>> G; vector<bool> cut;
  PushRelabelMaxFlow(int V, FlowUnit FLOW_EPS = FlowUnit(1e-9))
      : V(V), FLOW_EPS(FLOW_EPS), G(V) {}
  void addEdge(int v, int w, FlowUnit vwCap, FlowUnit wvCap = FlowUnit()) {
    if (v == w) return;
    G[v].emplace_back(w, int(G[w].size()), vwCap);
    G[w].emplace_back(v, int(G[v].size()) - 1, wvCap);
  }
  FlowUnit getFlow(int s, int t) {
    cut.assign(V, false); if (s == t) return FlowUnit();
    vector<FlowUnit> ex(V, FlowUnit()); vector<int> h(V, 0), cnt(V * 2, 0);
    vector<vector<int>> hs(V * 2);
    vector<typename vector<Edge>::iterator> cur(V);
    auto push = [&] (int v, Edge &e, FlowUnit df) {
      int w = e.to;
      if (abs(ex[w]) <= FLOW_EPS && df > FLOW_EPS) hs[h[w]].push_back(w);
      e.resCap -= df; G[w][e.rev].resCap += df; ex[v] -= df; ex[w] += df;
    };
    h[s] = V; ex[t] = FlowUnit(1); cnt[0] = V - 1;
    for (int v = 0; v < V; v++) cur[v] = G[v].begin();
    for (auto &&e : G[s]) push(s, e, e.resCap);
    if (!hs[0].empty()) for (int hi = 0; hi >= 0;) {
      int v = hs[hi].back(); hs[hi].pop_back(); while (ex[v] > FLOW_EPS) {
        if (cur[v] == G[v].end()) {
          h[v] = INT_MAX; for (auto e = G[v].begin(); e != G[v].end(); e++)
            if (e->resCap > FLOW_EPS && h[v] > h[e->to] + 1)
              h[v] = h[(cur[v] = e)->to] + 1;
          cnt[h[v]]++;
          if (--cnt[hi] == 0 && hi < V) for (int w = 0; w < V; w++)
            if (hi < h[w] && h[w] < V) { cnt[h[w]]--; h[w] = V + 1; }
          hi = h[v];
        } else if (cur[v]->resCap > FLOW_EPS && h[v] == h[cur[v]->to] + 1) {
          push(v, *cur[v], min(ex[v], cur[v]->resCap));
        } else cur[v]++;
      }
      while (hi >= 0 && hs[hi].empty()) hi--;
    }
    for (int v = 0; v < V; v++) cut[v] = h[v] >= V;
    return -ex[s];
  }
};
 
int main(){
    scanf("%d %d", &n, &m);

    PushRelabelMaxFlow<FlowEdge<ll>> mf(n+m+5);
    PushRelabelMaxFlow<FlowEdge<ll>> mff(n+m+5);


    
   
    int tot = 2;

    for(int i = 0; i < n ;i ++){
        int lo, hi; scanf("%d %d", &lo, &hi);

        a[tot] -= lo;
        a[1] += lo;

        mf.addEdge(tot,1,hi-lo);
        mf.addEdge(1,tot,0);
        mff.addEdge(tot,1,hi-lo);
        mff.addEdge(1,tot,0);
        tot++;
       
    }

     


    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &tmp[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int hi; scanf("%d", &hi);

            a[n+j+2] -= tmp[i][j];
            a[i+2] += tmp[i][j];

            mf.addEdge(n+j+2, i+2, hi-tmp[i][j]);
            mf.addEdge(i+2, n+j+2, 0);

            mff.addEdge(n+j+2, i+2, hi-tmp[i][j]);
            mff.addEdge(i+2, n+j+2, 0);
        }
    }

   

    for(int i = 0; i < m; i++){
        int lo, hi; scanf("%d %d", &lo, &hi);

        a[0] -= lo;
        a[tot+i] += lo;

        mf.addEdge(0, tot+i, hi-lo);
        mf.addEdge(tot+i, 0, 0);
        mff.addEdge(0, tot+i, hi-lo);
        mff.addEdge(tot+i, 0, 0);
        
    }
    
    s = n+m+2;
    t = n+m+3;

    for(int i = 0; i <= n+m+1; i++){
        if(a[i] > 0){
            mf.addEdge(s, i, a[i]);
            mf.addEdge(i,s,0);
            mff.addEdge(s, i, a[i]);
            mff.addEdge(i,s,0);
            sum += a[i];
        }
        else{
            mf.addEdge(i, t, -a[i]);
            mf.addEdge(t, i, 0);
            mff.addEdge(i, t, -a[i]);
            mff.addEdge(t, i, 0);
        }
        
    }
    mf.addEdge(1,0,INF);
    mf.addEdge(0,1,0);
    mff.addEdge(1,0,INF);
    mff.addEdge(0,1,0);
    
    ll ans = mf.getFlow(s,t);
    mff.getFlow(s,t);

    if(ans != sum) printf("%d\n", -1);
    else{

        long long temp = INF-mf.getFlow(1,0);        

        printf("%lld\n%lld\n", temp, mff.getFlow(0,1));
        
    }
}