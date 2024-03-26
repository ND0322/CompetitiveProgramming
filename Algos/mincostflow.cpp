#include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <unordered_map>


using namespace std;
#define pb push_back
const int N = 405;
const int INF = 0x3f3f3f3f;

struct edge {
    int v, c, w, id;
};
vector<edge> e[N];
int n, m, ans, tot, dist[N], cnt[N];

int pp;

int id = 7;

unordered_map<string, int> nametoid;


bitset<N> inq;

inline bool spfa() {
    queue<int> q;
    inq.reset();
    memset(dist, 0x3f, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    dist[1] = 0;
    q.push(1);
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
    return dist[2] != INF;
}

inline int dfs(int u = 1, int f = INF) {
    if(u == 2) {
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

void addEdge(int u, int v, int c, int w){
    e[u].pb({v, c, w, (int)e[v].size()});
    e[v].pb({u, 0, -w, (int)e[u].size() - 1});
}
void add(string name, int cs, int robo, int buis, int draf){
    nametoid[name] = id;
    addEdge(1, id, 2, 0);
    addEdge(id, 3,1, cs);
    addEdge(id, 4,1, robo);
    addEdge(id, 5,1, buis);
    addEdge(id, 6,1, draf);
    id++;
    pp++;
}


void query(string name){
    cout << "\n" << name << "\n";
    for(edge ee:e[nametoid[name]]){
        //cout << nametoid[name] << " " << ee.v << " "<< ee.c << " " << ee.v << "\n";
        if(!ee.c){
            if(ee.v == 3)cout <<"cs\n";
            if(ee.v == 4)cout <<"robi\n";
            if(ee.v == 5)cout <<"buis\n";
            if(ee.v == 6)cout <<"draft\n";
        }
    }
}

int main() {
    addEdge(3, 2, 20, 0);
    addEdge(3,2,5, 10000);
    addEdge(4, 2, 20, 0);
    addEdge(4,2,5, 10000);
    addEdge(5, 2, 20, 0);
    addEdge(5,2,5, 10000);
    addEdge(6, 2, 20, 0);
    addEdge(6,2,5, 10000);

    for(int i= 3; i <= 6; i++){
        for(edge ee:e[i]) if(ee.v == 2) cout << i << " " << ee.c << " " << ee.id << " " << ee.w << "\n";
    }

    add("joe", 4, 3, 2 ,1);
    add("tom", 2, 3, 1, 4);
    add("a", 2, 3, 1, 4);
    add("b", 2, 3, 1, 4);
    add("c", 2, 3, 1, 4);
    add("d", 2, 3, 1, 4);
    add("e", 2, 3, 1, 4);
    add("f", 2, 3, 1, 4);
    add("g", 2, 3, 1, 4);
    add("h", 2, 3, 1, 4);
    add("i", 2, 3, 1, 4);
    add("j", 2, 3, 1, 4);
    add("k", 2, 3, 1, 4);
    add("l", 2, 3, 1, 4);
    add("m", 2, 3, 1, 4);
    add("n", 2, 3, 1, 4);
    add("o", 2, 3, 1, 4);
    add("p", 2, 3, 1, 4);
    add("q", 2, 3, 1, 4);
    add("r", 2, 3, 1, 4);
    //add("s", 2, 3, 1, 4);
    //add("t", 2, 3, 1, 4);
    //add("u", 2, 3, 1, 4);
    //add("v", 2, 3, 1, 4);
    //add("w", 2, 3, 1, 4);
    //add("x", 2, 3, 1, 4);
    //add("y", 2, 3, 1, 4);
    //add("z", 2, 3, 1, 4);
    add("shanyu", 1, 4, 2, 3);
    add("frank", 1, 3, 2, 4);
    add("milan", 1, 3, 2, 4);
    add("bob", 1, 3, 2, 4);
    add("ruper", 1, 3, 2, 4);
    add("me", 1, 2, 3, 4);

    /*
    cout << "BEFORE\n";

    for(int i = 1; i <= id; i++){
        for(edge j : e[i]){
            cout <<"ori\n";
            cout << i << " " << j.v << " " << j.c << " " << j.w << "\n";
            cout << "res\n";
            cout << e[j.v][j.id].c << " " << e[j.v][j.id].w << "\n";
        }
    }
    */

    



    while(spfa()) ans += dfs();

    /*
    cout << "\nAFTER\n\n";
   

    for(int i = 1; i <= id; i++){
        for(edge j : e[i]){
            cout << i << " " << j.v << " " << j.c << " " << j.w << "\n";
            cout << "res\n";
            cout << e[j.v][id].c << " " << e[j.v][id].w << "\n";
        }
    }
    */
    


    cout << ans << " " << tot << "\n";
    query("a");
    query("b");
    query("c");
    query("d");
    query("e");
    query("f");
    query("g");
    query("h");
    query("i");
    query("j");
    query("k");
    query("l");
    query("m");
    query("n");
    query("o");
    query("p");
    query("q");
    query("r");
    query("joe");
    query("tom");
    query("shanyu");


    
}