#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace __gnu_pbds;
using namespace std;

const int MAXN = 1e4+5;
const int MAXP = 2005;
const int MAXD = 10;

int n, m, q, low[MAXN], disc[MAXN], comp[MAXN], t, cnt, jmp[MAXP][MAXD], sm[MAXP][MAXD][2], depth[MAXP], rt[MAXP], mp[MAXP];

gp_hash_table<int,int> dist[MAXN], distRev[MAXN], adj[MAXN];

vector<pair<int,int>> adj2[MAXN], adjRev[MAXN];

vector<int> adjSplit[MAXP];

vector<pair<int,pair<int,pair<int,int>>>> adjSCC[MAXP];

pair<int,int> edges[MAXP];


stack<int> st;

bitset<MAXN> in;

/*
condensation graph
split a component into the in node and out node
there will be a directed edge going from in node to out node with the cyclic distance going in to out
going from out to in is opposite cyclic distance 
just apsp for the pos stuff
*/

void tarjans(int node){
    low[node] = disc[node] = ++t;
    in[node] = 1;
    st.push(node);

    for(auto [child, weight] : adj[node]){
        if(!disc[child]){
            tarjans(child);
            low[node] = min(low[node], low[child]);
        }
        else if(in[child]) low[node] = min(low[node], disc[child]);
    }

    if(low[node] == disc[node]){
        cnt++;
        while(st.top() != node){
            comp[st.top()] = cnt;
            in[st.top()] = 0;
            st.pop();
        }

        comp[node] = cnt;
        in[node] = 0;
        st.pop();
    }
}

void dijk(int rt){
    dist[rt][rt] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, rt});

    while(pq.size()){
        auto [d,node] = pq.top();

        pq.pop();

        if(dist[rt][node] != d) continue;

        for(auto [child, weight] : adj2[node]){
            if(dist[rt].find(child) == dist[rt].end()) dist[rt][child] = 1e9;
            if(dist[rt][child] > d + weight){
                dist[rt][child] = d + weight;
                pq.push({d+weight, child});
            }
        }
    }
}

void dijkRev(int rt){
    distRev[rt][rt] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, rt});

    while(pq.size()){
        auto [d,node] = pq.top();

        pq.pop();

        if(distRev[rt][node] != d) continue;

        for(auto [child, weight] : adjRev[node]){
            if(distRev[rt].find(child) == distRev[rt].end()) distRev[rt][child] = 1e9;
            if(distRev[rt][child] > d + weight){
                distRev[rt][child] = d + weight;
                pq.push({d+weight, child});
            }
        }
    }
}

void dfs(int node, int par, int entry){
    rt[node] = entry;
    for(auto [child, stuff] : adjSCC[node]){
        if(child == par) continue;
        cnt++;
        mp[cnt] = stuff.second.first;
        adjSplit[node].push_back(cnt);
        adjSplit[cnt].push_back(node);
        edges[cnt] = {dist[entry][stuff.second.first], dist[stuff.second.first][entry]};

        adjSplit[cnt].push_back(child);
        adjSplit[child].push_back(cnt);
        edges[child] = {stuff.first, stuff.first};
        dfs(child, node, stuff.second.second);
    }
}

void init(int node){
    for(int i = 1; i < MAXD; i++){
        jmp[node][i] = jmp[jmp[node][i-1]][i-1];
        sm[node][i][0] = sm[node][i-1][0] + sm[jmp[node][i-1]][i-1][0];
        sm[node][i][1] = sm[node][i-1][1] + sm[jmp[node][i-1]][i-1][1];
    }

    for(int child : adjSplit[node]){
        if(child == jmp[node][0]) continue;
        jmp[child][0] = node;
        sm[child][0][0] = edges[child].first;
        sm[child][0][1] = edges[child].second;
        depth[child] = depth[node]+1;

        init(child);
    }
}

pair<int,pair<int,int>> lift(int node, int d){
    pair<int,int> ans = {0,0};
    for(int i = 0; i < MAXD; i++){
        if(d & (1<<i)){
            ans.first += sm[node][i][0];
            ans.second += sm[node][i][1];
            node = jmp[node][i];
        }
    }
    return {node, ans};
}

int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);
    x = lift(x, depth[x] - depth[y]).first;
    if(x == y) return x;

    for(int i = MAXD-1; i >= 0; i--){
        if(jmp[x][i] != jmp[y][i]){
            x = jmp[x][i];
            y = jmp[y][i];
        }
    }

    return jmp[x][0];
}



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m >> q;

    for(int i = 0; i < m; i++){
        int x,y, c; cin >> x >> y >> c;

        if(adj[x].find(y) == adj[x].end()) adj[x][y] = c;
        else adj[x][y] = min(adj[x][y], c);
    }


    for(int i= 1; i <= n; i++){
        if(!disc[i]) tarjans(i);
    }

    in.reset();


    for(int i = 1; i <= n; i++){
        for(auto [child, weight] : adj[i]){
            if(comp[i] == comp[child]){
                adj2[i].push_back({child, weight});
                adjRev[child].push_back({i, weight});
                continue;
            }
            in[i] = 1;
            in[child] = 1;
            adjSCC[comp[i]].push_back({comp[child], {weight, {i, child}}});
            adjSCC[comp[child]].push_back({comp[i], {weight, {child, i}}});
        }
    }

    for(int i = 1; i <= n; i++){
        if(in[i] || i == 1){
            dijk(i);
            dijkRev(i);
        }
    }

    dfs(comp[1], -1, 1);
    init(comp[1]);


    while(q--){
        int x, y; cin >> x >> y;

        //precomp the reverse distance    
        int l = lca(comp[x],comp[y]);
        int ans = dist[rt[comp[y]]][y] + distRev[rt[comp[x]]][x];


        //if x is ancestor of y or vice versa special case 

        if(comp[x] == comp[y]){
            if(in[x] || x == 1){
                cout << dist[x][y] << "\n";
                continue;
            }

            if(in[y] || y == 1){
                cout << distRev[y][x] << "\n";
                continue;
            }
            dijk(x);
            cout << dist[x][y] << "\n";
            continue;
        }

        if(comp[x] == l){
            auto a = lift(comp[y], depth[comp[y]] - depth[l] - 1);
            cout << distRev[mp[a.first]][x] + a.second.first + dist[rt[comp[y]]][y] << "\n";
            continue;
        }
        if(comp[y] == l){
            auto a = lift(comp[x], depth[comp[x]] - depth[l] - 1);
            cout << dist[mp[a.first]][y] + a.second.second + distRev[rt[comp[x]]][x] << "\n";
            continue;
        }

        auto a = lift(comp[x], depth[comp[x]] - depth[l]-1);
        auto b = lift(comp[y], depth[comp[y]] - depth[l]-1);
        ans += a.second.second;
        ans += b.second.first;
        ans += dist[mp[a.first]][mp[b.first]];

        cout << ans << "\n";

    }

}