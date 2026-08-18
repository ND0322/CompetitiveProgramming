#include <bits/stdc++.h>
#include <iostream>


using namespace std;

typedef long double ld;

const int MAXN = 1e6+5;
const double INF = 1e6+5;
const long double LINF = 1e18;


int n, a[MAXN], k, cnt[MAXN];

long long place[MAXN];

ld dp[MAXN];

set<int> pos[MAXN];

bool mini = false;



//(y - x + 1)^2 + dp[j+1]
//(a - x) ^ k + b

struct Line{
  ld a,b;

  Line(){
    a = b = LINF;
  }

  Line(ld _a, ld _b){
    a = _a;
    b = _b;
  }

  ld operator()(int x){

    if(k == 4) return a * x + b;
    ld base = a - x;
    if(base < 0) return -LINF;
    return (a-x) * sqrt(a-x) + b;
  }
}; 



struct Lichao{
  struct Node{
    Line line;
    Node *lchild = nullptr;
    Node *rchild = nullptr;
    bool hasLine = false;
  };

  Node *root;

  Lichao(){
    root = new Node;
  }

  void addLine(Line a, Node* &x, int l, int r, int p){

    if(l >= p) return;
    if(x == nullptr){
      x = new Node;
    }

    if(r > p){
      int mid = (l+r)/2;
      addLine(a, x->lchild, l, mid, p);
      addLine(a, x->rchild, mid, r, p);
      return;
    }

    if(!x->hasLine){
      x->line = a;
      x->hasLine = true;
      return;
    }

    int mid = (l+r)/2;

    if(a(mid) > x->line(mid)){
      swap(a, x->line);
    }

    if(l + 1 == r){
      return;
    }

    if((a(mid) > x->line(mid)) == (a(l) > x->line(l))){
      addLine(a, x->rchild, mid, r, p);
    } else {
      addLine(a, x->lchild, l, mid, p);
    }
  }

  void addLine(Line a, int hi){
    addLine(a, hi, hi);
  }

  void addLine(Line a, int hi, ld r){
    int p = (int)min((ld)hi, r) + 1;
    addLine(a, root, 1, hi, p);
  }

  ld query(int p, Node *x, int l, int r){
    if(x == nullptr){
      return -LINF;
    }

    ld ans = x->hasLine ? x->line(p) : -LINF;
    int mid = (l+r)/2;

    if(p < mid){
      ans = max(ans, query(p, x->lchild, l, mid));
    } else {
      ans = max(ans, query(p, x->rchild, mid, r));
    }

    return ans;
  }

  ld query(int p, int hi){
    return query(p, root, 1, hi);
  }
} trees[MAXN]; 




int main(){

  cin.tie(NULL) -> ios_base::sync_with_stdio(0);
  
  cin >> k >> n;

  for(int i = 1; i <= n; i++){
      cin >> a[i];
      pos[a[i]].insert(i);
  }

  for(int i = 1; i <= n; i++){
      cnt[a[i]]++;
      place[i] = cnt[a[i]];
  }
  


  if(k == 2){
      cout << n << "\n";
      return 0;
  }

  for(int i = n; i >= 1; i--){
      dp[i] = trees[a[i]].query(place[i], cnt[a[i]]);
      if (dp[i] < -LINF) {
        dp[i] = -LINF;
      }


      if(k == 4){
          dp[i] += place[i] * place[i] - 2 * place[i] + 1;
          dp[i] = max(dp[i], dp[i+1] + 1);
          Line l;

          l.a = -2 * place[i];
          l.b = 2 * place[i] + place[i] * place[i] + dp[i+1];
          trees[a[i]].addLine(l, cnt[a[i]]);
      }
      else{
          dp[i] = max(dp[i], dp[i+1] + 1);
          Line l;

          l.a = place[i] + 1;
          l.b = dp[i+1];

          trees[a[i]].addLine(l, cnt[a[i]]);
      }
  
  }

  cout << fixed << setprecision(6) << dp[1] << "\n";
}