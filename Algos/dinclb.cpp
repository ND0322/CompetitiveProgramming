#include <bits/stdc++.h>
#include <iostream>
#include <queue>


typedef long long ll;
 
 
using namespace std;
 
const int MAXN = 1e6+100;
const int MAXM = 1e6+100;
const int INF = 1e9;

//https://loj.ac/p/117
 
int n, m, cnt = 1, s, t, ss,tt, level[MAXN], cur[MAXN], head[MAXN], a[MAXN], l[MAXN], sum;

bitset<MAXN> visited;
 
 
struct edge {
    int u,v,f,nxt;
    
} e[MAXM];
 
void add(int u, int v, int c){
    e[++cnt] = {u,v,c,head[u]};
    head[u] = cnt;
}

void ad(int u, int v, int hi, int lo){
    a[u] -= lo;
    a[v] += lo;

    add(u,v,hi-lo);
    l[cnt] = lo;
    add(v,u,0);

}

void init(){
    s = n+1;
    t = n+2;

    for(int i = 1; i <= n; i++){
        if(a[i] > 0){
            add(s, i, a[i]);
            add(i,s,0);
            sum += a[i];
        }
        else add(i, t, -a[i]), add(t, i, 0);
        
    }
    add(tt,ss,INF);
    add(ss,tt,0);
}
 
bool bfs(){
    queue<int> q;
 
    memset(level, 0, sizeof(level));
    for(int i = 1;i<=n + 2;++i) cur[i] = head[i];
 
    level[s] = 1;
    q.push(s);
 
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
    return level[t];
}
 
int dfs(int node = s, int flow = INF){
    if(node == t) return flow;
    int ans = 0;
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
 
int dinics(){
    int ans = 0;
 
    while(bfs()) ans += dfs();
    return ans;
}

int minflow(){
    ll ans = dinics();


    if(ans != sum) return -1;
    
    s = tt;
    t = ss;

    return dinics();
}
 
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m >> ss >> tt;
    

    for(int i = 0; i < m; i++){
        int x,y,lo,hi; cin >> x >> y >> lo >> hi;

        ad(x,y,hi,lo);        
    }
    
    init();


    //run dinics on s = ss, t = tt for max

    int ans = minflow();
    if(ans == -1) cout << "please go home to sleep\n";
    else cout << INF-ans << "\n";
    
   
}