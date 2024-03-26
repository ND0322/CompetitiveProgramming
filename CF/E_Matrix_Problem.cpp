
#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#include <queue>

#define int long long
using namespace std;
#define pb push_back
const int N = 105;
const long long INF = 1LL << 61;
const int BIG = 1e9;
struct edge {
    int v, c, w, id;
};
vector<edge> e[N];
int n, m, ans, tot, dist[N], cnt[N];

bitset<N> inq;

int a[55], b[55], idr[55],idc[55];
bool grid[55][55];


inline bool spfa() {
    queue<int> q;
    inq.reset();
    fill(dist, dist+n+m+3, INF);
    memset(cnt, 0, sizeof(cnt));
    dist[0] = 0;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(auto[v, c, w, id] : e[u]) {
            if(c > 0 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if(!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    inq.reset();
    return dist[1] != INF;
}

inline int dfs(int u = 0, int f = INF) {
    if(u == 1) {
        tot += f * dist[u];
        return f;
    }
    int ret = 0;
    inq[u] = 1;
    for(int& i = cnt[u];i<e[u].size();++i) {
        auto&[v, c, w, id] = e[u][i];
        if(!inq[v] && c > 0 && dist[v] == dist[u] + w) {
            int tmp = dfs(v, min(c, f));
            ret += tmp;
            c -= tmp;
            e[v][id].c += tmp;
            f -= tmp;
            if(f == 0) break;
        }
    }
    inq[u] = 0;
    if(ret == 0) dist[u] = INF;
    return ret;
}

int32_t main() {
    cin>>n>>m;

    //build row and column reqs

    //mayb need to add lower bounds

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    

    int rs = 0;
    int cs = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        rs += x;


        e[0].pb({i+2, x, 0, (int)(e[i+2].size())});
        e[i+2].pb({0,0, 0, (int)e[0].size()-1});

        
    }

    for(int i = 0; i < m; i++){

        int x; cin >> x;
        cs += x;


        e[i+n+2].pb({1,x, 0, (int)e[1].size()});
        e[1].pb({i+n+2, 0, 0, (int)(e[i+n+2].size()-1)});
    }

    if(rs != cs){
        cout << "-1\n";
        return 0;
    }

    int tmp = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tmp += grid[i][j];
            //cout << idr[i] << " " << idc[j] << "\n";
            e[i+2].pb({j+n+2, 1, BIG +2*(grid[i][j]==0)-1, (int)e[j+n+2].size()});
            e[j+n+2].pb({i+2, 0, -(BIG + 2*(grid[i][j]==0)-1), (int)e[i+2].size()-1});

            //e[idr[i]].pb({idc[j], 1, grid[i][j], (int)e[idc[j]].size()});
            //e[idc[j]].pb({1, 0, -grid[i][j], (int)e[idc[i]].size()-1});
        }
    }

    
    //cout << tmp << "\n";
   
    while(spfa()) ans += dfs();

    
   


    if(ans != rs){
        cout << "-1\n";
        return 0;
    }


    cout << tot - BIG * rs + tmp;
    return 0;
}