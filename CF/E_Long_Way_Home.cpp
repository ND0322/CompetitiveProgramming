#include <bits/stdc++.h>
#include <queue>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;
const long long MAXB = 1e12+10;
const long long LINF = 1e18+10;
const int INF = 1e9+10;

typedef long long ll;
typedef pair<ll,int> pii;

int n,m,k;

bool mini = false;


vector<pii> adj[MAXN];

priority_queue<pii,vector<pii>,greater<pii>> pq;

ll distances[MAXN];

struct Line{
    ll m,b;

    Line(){
        m = b = LINF;
    }

    Line(ll _m, ll _b){
        m = _m;
        b = _b;
    }

    ll operator()(ll x){
        return m*x+b;
    }

};

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

void dijkstras(){
    vector<int> visited(n+1,false);

    for(int i = 1; i <= n; i++){
        pq.push({distances[i],i});
    }

    while(!pq.empty()){
        
        int node = pq.top().second;

        pq.pop();

        if(visited[node]) continue;

        visited[node] = true;

        for(pii c:adj[node]){
            int child = c.first;
            int weight =c.second;

            if(distances[child] > distances[node] + weight){
                distances[child] = distances[node] + weight;
                pq.push({distances[child],child});
            }
        }
    }


}

int main(){
    cin >> n >> m >> k;

    cout << n << ' ' << m << " " << k << endl;

    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        adj[y].push_back({x,c});

    }

    fill(distances,distances+n+1,INF);

    distances[1] = 0;

    dijkstras();

    Lichao tree;


    for(int i = 0; i < k; i++){
        for(int j = 2; j <= n; j++){
            tree.addLine({-2*j,distances[j] + j*j});
        }

        for(int j = 1; j <= n; j++){
            distances[j] = tree.query(j) + j*j;
            cout << distances[j] << endl;
        }

        dijkstras();
    } 

    

    for(int i = 1; i <= n; i++){

        cout << distances[i] << " ";
    }
    cout << endl;
}