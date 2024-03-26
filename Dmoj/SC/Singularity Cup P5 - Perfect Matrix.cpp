#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;



 
 
using namespace std;
 
const int MAXN = 2500;
const int MAXM = 4e6+500;
const ll INF = 1e18;


 
int n, m, cnt = 1, s, t, level[MAXN], cur[MAXN], head[MAXN], x[MAXM], y[MAXM];
ll l[MAXM], a[MAXN], ans[1005][1005], lo[1005][1005], hi[1005][1005];
int row[1005], col[1005];


 
bitset<MAXN> visited;
 
 
struct edge {
    ll u,v,f,nxt;
    
} e[MAXM];
 
void add(int u, int v, ll c){
    e[++cnt] = {u,v,c,head[u]};
    head[u] = cnt;
}
 
inline bool bfs(){
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
 
inline ll dfs(int node = s, ll flow = INF){
    if(node == t) return flow;
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
 
inline ll dinics(){
    ll ans = 0;
 
    while(bfs()) ans += dfs();
    return ans;
}


int main(){

    cin.tie(NULL) -> ios_base::sync_with_stdio(0);


    //Source to col
    //col to row edges are cells
    //row to sink
    

    cin >> n >> m;

    

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)cin >> lo[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)cin >> hi[i][j];
    int tmp = 2;
    

    for(int i = 0; i < n; i++){
        row[i] =tmp;
        tmp++;
    }

    for(int i = 0; i < m; i++){
        col[i] = tmp;
        tmp++;
    }

    


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            add(row[i], col[j], hi[i][j] - lo[i][j]);
            x[cnt] = i;
            y[cnt] = j;
            l[cnt] = lo[i][j];
            add(col[j], row[i], 0);
            a[row[i]] -= lo[i][j];
            a[col[j]] += lo[i][j];
        }
    }

   



    for(int i = 0; i < n; i++){
        int low, high; cin >> low >> high;

        add(0, row[i], high-low);
        add(row[i], 0, 0);
        a[0] -= low;
        a[row[i]] += low;
    }

    for(int i = 0; i < m; i++){
        int low, high; cin >> low >> high;

        add(col[i], 1, high-low);
        add(1,col[i], 0);
        a[col[i]] -= low;
        a[1] += low;
    }

    

  

    s = tmp;
    t = tmp+1;

  

    

    ll sum = 0;
    for(int i = 0; i <= tmp; i++){
        if(a[i] > 0){
            add(s,i,a[i]);
            add(i,s,0);
            sum += a[i];

        }
        else add(i, t, -a[i]), add(t, i, 0);
    }    

    add(1,0,INF);
    add(0,1,0);

   
   


    
    
    if(dinics() == sum){
        for(int i = 2; i <= n*m*2; i += 2) ans[x[i]][y[i]] = e[i^1].f + l[i];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
        
    }
    else cout << "-1\n";
    

   
}