#include <bits/stdc++.h>
#include <iostream>
#include <queue>



using namespace std;

const int MAXN = 2005;
const int MAXM = 2e5+5;
const int INF = 1e9;

int n, m, cnt = 1, s= 1, t, level[MAXN], cur[MAXN], head[MAXN];

bitset<MAXN> visited;


struct edge {
    int u,v,f,nxt;
} e[MAXM];

void add(int u, int v, int c){
    e[++cnt] = {u,v,c,head[u]};
    head[u] = cnt;
    e[++cnt] = {v,u,0, head[v]};
    head[v] = cnt;
}

bool bfs(){
    queue<int> q;

    memset(level, 0, sizeof(level));
    memcpy(cur, head, sizeof (cur));

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

int dfs(int node = 1, int flow = INF){
    if(node == t) return flow;
    int ans = 0;
    visited[node] = 1;

    for(int& i = cur[node]; i > 0; i = e[i].nxt){
        if(e[i].f && !visited[e[i].v] && level[e[i].v] == level[node]+1){
            int res = dfs(e[i].v, min(flow,e[i].f));

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

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> m >> n;

   

    for(int i = 1; i <= m; i++){
        int x; cin >> x;

        if(!x) t = i;
        add(i, i+m, x);

        
    }

    for(int i = 0; i < n; i++){
        int x,y;cin >> x >> y;

        add(x+m,y,INF);
    }

    cout << dinics() << "\n";

   
    
}