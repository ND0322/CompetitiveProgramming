#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


const int MAXN = 1e5+5;


int n,q, v[MAXN], c[MAXN], s[MAXN], depth[MAXN], top[MAXN], sz[MAXN], heavy[MAXN], par[MAXN], pos[MAXN], t, st[MAXN<<2], ans[MAXN], tmp[MAXN];

vector<pair<pair<int,int>, pair<int,int>>> adj[MAXN];



/*
we're gonna try to raw dog parallel binary search 
*/

struct Query{
    int a,b,id, cap;

    Query(int _a, int _b, int _id, int _cap){
        a = _a;
        b = _b;
        id = _id;
        cap = _cap;
    }
};

struct Event{
    int i, t, v;

    Event(int _i, int _t, int _v){
        i = _i;
        t = _t;
        v = _v;
    }

    bool operator<(const Event& b){
        return t > b.t;
    }

};


void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;

    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1, r, i, x);
    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return query(node<<1,l,mid,x,y) + query(node<<1|1, mid+1, r, x,y);
}



void dfs(int node){
    sz[node] = 1;

    for(auto e : adj[node]){
        int child = e.first.first;

        if(child == par[node]) continue;

        v[child] = e.first.second;
        c[child] = e.second.first;
        s[child] = e.second.second;

        depth[child] = depth[node]+1;
        par[child] = node;
        dfs(child);
        sz[node] += sz[child];
        if(sz[child] > sz[heavy[node]]) heavy[node] = child;
    }
}


void hld(int node, int rt){
    pos[node] = ++t;
    top[node] = rt;

    if(heavy[node]){
        hld(heavy[node], rt);
        for(auto e : adj[node]){
            int child = e.first.first;
            if(par[node] == child || child == heavy[node]) continue;
            hld(child, child);
        }
    }
}


int qpath(int x, int y){
    int ans = 0;

    while(top[x] != top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x,y);

        ans += query(1,1,n, pos[top[x]], pos[x]);
        x = par[top[x]];
    }

    if(depth[x] > depth[y]) swap(x,y);

    ans += query(1,1,n, pos[x]+1, pos[y]);
    return ans;
}



void dac(int l, int r, vector<Query> queries, vector<Event> events){

    if(queries.empty()) return;
    if(r == l+1){
        for(auto i : queries) ans[i.id] = l;
        return;
    }

    int mid = (l+r)>>1;

    //minimum >= mid
    //for any edges that have weight < mid, we have to try to upgrade it
    //if the upgrade speed is still < mid, then this edge is invalid, lets add infinity as its cost



    vector<Event> le, re;

    vector<int> ord;
    for(auto i : events){
        if(i.t <= mid){
            le.push_back(i);
            tmp[i.i] = query(1,1,n, pos[i.i], pos[i.i]);
            update(1,1,n, pos[i.i], i.v);
            
        }
        if(i.t > mid) re.push_back(i);        
    }

    vector<Query> lq, rq;
    for(auto i : queries){
        //if its good then we move it to the right
        //else left

        //cout << i.a << " " << i.b << " " << mid << " " << qpath(i.a, i.b) << "\n";

        if(qpath(i.a, i.b) <= i.cap) rq.push_back(i);
        else lq.push_back(i);
    }

    for(auto i : le) update(1,1,n, pos[i.i], tmp[i.i]);

    dac(l, mid, lq, le);
    dac(mid, r, rq, re);
    
   
}

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n-1; i++){
        int x,y, wi, cc, wf; cin >> x >> y >> wi >> cc >> wf;

        adj[x].push_back({{y, wi}, {cc, wf}});
        adj[y].push_back({{x, wi}, {cc, wf}});
    }

    cin >> q;

    vector<Query> queries;

    for(int i = 1; i <= q; i++){
        int x,y, c; cin >> x >> y >> c;

        queries.push_back(Query(x,y,i, c));
    }

    

    dfs(1);
    hld(1,1);

    vector<Event> events;

    for(int i = 2; i <= n; i++){
        events.push_back(Event(i, 1, 0));
        events.push_back(Event(i, v[i]+1, c[i]));
        events.push_back(Event(i, s[i]+1, 1e14));
    }

    dac(1,1e9+1, queries, events);

    for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
}