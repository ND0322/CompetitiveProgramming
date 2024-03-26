#include <bits/stdc++.h>
#include <iostream>
#include <map>


using namespace std;

const int MAXN = 1e5+5;
const int INF = 1e9;
const long long LINF = 1e18;

typedef long long ll;

//solves https://dmoj.ca/problem/dmopc15c2p5
bool mini = false;
//set this to true to query min
int n, q;



struct Line{
  ll m,b, id;

  Line(){
    m = b = INF;
    id = 1e9;
  }

  Line(ll _m, ll _b, int _id){
    m = _m;
    b = _b;
    id = _id;
  }

  ll operator()(int x){
    return m*x+b;
  }
}; 



struct Lichao{
  struct Node{
    Line line;
    Node *lc;
    Node *rc;
  };

  Node *root;

  Lichao(){
    root = new Node;
  }

  void addLine(Line a, Node* &x, int l, int r){
    bool leaf = false;
    if(x == nullptr){
      x = new Node;
      leaf = true;
    }

    int mid = (l+r)>>1;

    if(a(mid) < x -> line(mid)) swap(a,x->line);
    

    if(leaf || l + 1 == r) return;
    
    if((a(mid) < x -> line(mid) == (a(l) < x -> line(l)))) addLine(a,x->rc,mid,r);
    else addLine(a,x -> lc,l,mid);
    
  }

  void addLine(Line a){
    if(!mini){
      a.b *= -1;
      a.m *= -1;
    }

    addLine(a,root,-INF,INF);
  }

  pair<long long,int> query(int p, Node *x, int l, int r){
    if(x == nullptr) return {LINF, LINF};
    

    pair<long long,int> ans = {x->line(p), x->line.id};

    int mid = (l+r)>>1;

    if(p < mid) ans = min(ans,query(p,x ->lc, l, mid));
    else ans = min(ans,query(p,x -> rc,mid,r));

    return ans;
  }

  pair<long long,int> query(int p){
    return query(p,root,-INF,INF);
  }
};

int main(){
  cin.tie(NULL) -> ios_base::sync_with_stdio(0);
  cin >> n >> q;

  Lichao lt;

  for(int i = 0; i < n; i++){
    long long m,b; cin >> b >> m;
    lt.addLine(Line(m,b, i));
  }

  while(q--){
    long long x; cin >> x;

    pair<long long, int> res = lt.query(x);

    cout << res.second << "\n";
  }
}