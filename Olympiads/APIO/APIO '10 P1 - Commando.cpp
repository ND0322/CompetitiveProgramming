#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

//dp[i] = maxj(dp[j] + ax^2 + bx + c)
//dp[i] = maxj(dp[j] + a(psa[j] - psa[i])^2 + b(psa[j] - psa[i]) + c)

//dp[i] = dp[j] + a(psa[j]^2 - 2psa[j]psa[i] + psa[i]^2) + b(psa[j] - psa[i]) + c

//dp[i] = dp[j] + a*psa[j]^2 - 2a*psa[j]psa[i] + a*psa[i]^2 + b*psa[j] - b*psa[i] + c

//dp[i] = (dp[j] + a*psa[j]^2 - 2a*psa[j]psa[i] + b*psa[j]) + a*psa[i]^2 - b*psa[i]+c

//dp[i] = ((dp[j] + a * psa[j]^2 + b * psa[j]) - 2a*psa[j]psa[i]) + a*psa[i]^2 - b * psa[i]+c

//m = 2a*psa[j]
//b = -b * psa[i] + a*psa[i]^2 + c

const int INF = 1e8;
const long long LINF = 1e18;

typedef long long ll;


bool mini = false;
int n;
ll dp[MAXN], a,b,c;


struct Line{
  ll m,b;

  Line(){
    m = b = INF;
  }

  Line(ll _m, ll _b){
    m = _m;
    b = _b;
  }

  ll operator()(int x){
    return m*x+b;
  }
}; 


//using this implementation cause the other ones memory too high

struct Lichao{
  struct Node{
    Line line;
    Node *lchild;
    Node *rchild;
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

    int mid = (l+r)/2;

    if(a(mid) < x -> line(mid)){
      swap(a,x->line);
    }

    if(leaf || l + 1 == r){
      return;
    }
    if((a(mid) < x -> line(mid) == (a(l) < x -> line(l)))){
      addLine(a,x->rchild,mid,r);
    }
    else{
      addLine(a,x -> lchild,l,mid);
    }
  }

  void addLine(Line a){
    if(!mini){
      a.b *= -1;
      a.m *= -1;
    }

    addLine(a,root,-INF,INF);
  }

  ll query(int p, Node *x, int l, int r){
    if(x == nullptr){
      return LINF;
    }

    ll ans = x -> line(p);

    int mid = (l+r)/2;

    if(p < mid){
      ans = min(ans,query(p,x -> lchild, l, mid));
    }
    else{
      ans = min(ans,query(p,x -> rchild,mid,r));
    }

    return ans;
  }

  ll query(int p){
    return (mini ? query(p,root,-INF,INF) : -query(p,root,-INF,INF));
  }
};




int main() {
  cin >> n >> a >> b >> c;

  Lichao tree;

  ll sum = 0;

  for(int i = 1; i <= n; i++){
    ll x; cin >> x;
    tree.addLine({-2*a*sum + b,dp[i-1] + c + -b * sum + a*sum*sum});

    sum+=x;

    dp[i] = tree.query(sum) + a*sum*sum;
    
  }

  cout << dp[n] << endl;
}