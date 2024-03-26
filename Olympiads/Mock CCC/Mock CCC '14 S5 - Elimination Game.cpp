#include <bits/stdc++.h>
#include <iostream>
#include <queue>



typedef long long ll;
 
 
using namespace std;
 
const int MAXN = 205;
const int MAXM = 5e4+5;
const ll INF = 1e18;


 
int n, m, cnt = 1, level[MAXN], cur[MAXN], head[MAXN], a[MAXN], b[MAXN];
 
bitset<MAXN> visited;

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}
 
 
struct edge {
    ll u,v,f,nxt;
    
} e[MAXM];
 
void add(int u, int v, ll c){
    e[++cnt] = {u,v,c,head[u]};
    head[u] = cnt;
    e[++cnt] = {v,u,0, head[v]};
    head[v] = cnt;
}
 
bool bfs(){
    queue<int> q;
 
    memset(level, 0, sizeof(level));
    memcpy(cur, head, sizeof (cur));
 
    level[0] = 1;
    q.push(0);
 
    while(!q.empty()){
        int node = q.front();
       
        q.pop();
 
        for(int i = head[node]; i > 0; i = e[i].nxt){
          
            if(e[i].f > 0 && !level[e[i].v]){
                level[e[i].v] = level[node]+1;
                q.push(e[i].v);
            }
        }
    }
 
    visited.reset();
    return level[1];
}
 
ll dfs(int node = 0, ll flow = INF){
    if(node == 1) return flow;
    ll ans = 0;
    visited[node] = 1;
 
    for(int& i = cur[node]; i > 0; i = e[i].nxt){
        if(e[i].f && !visited[e[i].v] && level[e[i].v] == level[node]+1){
            ll res = dfs(e[i].v, min(flow,e[i].f));
 
            e[i].f -= res;
            e[i^1].f += res;
            flow -= res;
            ans += res;
 
            if(!flow) break;
 
 
        }
    }
 
    visited[node] = 0;
    if(!ans) level[node] = 0;
    return ans;
 
 
 
}
 
ll dinics(){
    ll ans = 0;
 
    while(bfs()) ans += dfs();
    return ans;
}
 
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];

        add(0, i+1, 1);
    }

    for(int j = 1; j <= m; j++){
        cin >> b[j];

        add(j+n+1, 1, 1);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(gcd(a[i], b[j]) == 1) continue;
            add(i+1, j+n+1, 1);
        }
    }

    cout << dinics()*2 << "\n";


 
    
   
}