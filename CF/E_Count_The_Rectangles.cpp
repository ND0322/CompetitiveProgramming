#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;
const int MAXM = 1e4+5;

int n, st[MAXN<<2];

pair<pair<int,int>, pair<int,int>> a[MAXN];
 

/*
linesweep left to right

each vertical at x will be some binary mask



*/

void build(int node, int l, int r){
    if(l == r){
        st[node] = 0;
        return;
    }

    int mid = (l+r)>>1;

    build(node<<1,l,mid);
    build(node<<1|1, mid+1, r);
    st[node] = st[node<<1] + st[node<<1|1];
}

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] += x;
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

    int mid = (l+r);
    return query(node<<1, l, mid, x, y) + query(node<<1|1, mid+1, r, x, y);
}
    
    




int main(){
    cin >> n;

    vector<pair<int,pair<int,int>>> events;

    int m = 1;

    for(int i = 1; i <= n; i++){
        int x1,y1, x2,y2; cin >> x1 >> y1 >> x2 >> y2;

        x1 += 5001;
        x2 += 5001;
        y1 += 5001;
        y2 += 5001;

        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);

        a[i] = {{x1, y1}, {x2, y2}};

        if(x1 == x2) events.push_back({x1, {2, i}});
        else{
            events.push_back({x1, {1, i}});
            events.push_back({x2+1, {0, i}});
        }
    }

    sort(events.begin(), events.end());

    set<int> actvH;
    set<int> actvV;

    for(auto i : events){
        int x = i.first;
        auto [t, id] = i.second;

        if(t == 0) actvH.erase(a[id].first.second);
        if(t == 1) actvH.insert(a[id].first.second);

        for(int j : actvH) segs[x].update(1,1,MAXM, j, 1);

        if(t == 2){
            for(int j : actvV){
                int l = max(a[j].first.second, a[id].first.second);
                int r = min(a[j].second.second, a[id].second.second);

                if(l > r) continue;

                int cnt = 
            }

            actvV.insert(id);
        }
        
    }


}
