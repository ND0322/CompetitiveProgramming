#include <bits/stdc++.h>
#include <iostream>

const int MAXN = 1e5+5;
const int N = 1e9;


#define int long long

typedef long long ll;

using namespace std;

int n, k, p;

map<int, vector<int>> events;

struct Node{
    int lz = 0;
    int sm = 0;

    Node *lc = nullptr;
    Node *rc = nullptr;
}  *rt = new Node;



/*
2 types of events

add event at li + ti
remove event at ri 

we'll be left with some intervals that have k sum 

We can do a sparse seg tree with range add range sum 
*/

void pushdown(Node *node, int l, int r){
    
    if(node->lc == nullptr) node->lc = new Node;
    if(node->rc == nullptr) node->rc = new Node;

    if(!node->lz) return;
    int mid = (l+r)>>1;

    node->lc->sm += (mid - l + 1) * node->lz;
    node->rc->sm += (r-mid) * node->lz;

    node->lc->lz += node->lz;
    node->rc->lz += node->lz;
    node->lz = 0;
}


void update(Node *node, int l, int r, int x, int y, int v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        node->sm += (r-l+1) * v;
        node->lz += v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r);
    update(node->lc, l, mid, x, y, v);
    update(node->rc, mid+1, r, x, y, v);
    node->sm = node->lc->sm + node->rc->sm;
}

int query(Node *node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return node->sm;

    int mid = (l+r)>>1;

    pushdown(node,l,r);
    return query(node->lc, l, mid, x, y) + query(node->rc, mid+1,r,x,y);
}



int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k >> p;

    for(int i =1 ; i <= n; i++){
        int l, t,r; cin >> l >> t >> r;

        events[l].push_back(0);
        events[l+t].push_back(1);
        events[r+1].push_back(2);

        /*
        0 is add a car to car count
        1 is add to number of bad cars on this segment
        2 is remove from both
        */
    }

    int car = 0;
    int bad = 0;

    int lc = 0;
    int lb = 0;

    int l = -1;

    vector<pair<pair<int,int>, int>> ranges;

    for(auto [i, v] : events){

        for(int j : v){
            if(!j) car++;
            else if(j==1) bad++;
            else{
                car--;
                bad--;
            }
        }

        if(lc >= k) ranges.push_back({{l, i-1}, lb});
        
        lb = bad;
        lc = car;
        l = i;
    }
    

    for(auto [i, v]: ranges){
        auto [l,r] = i;

        update(rt, 1, N, l, r, v);
    }

    int ans = 0;

    for(auto [i, v]: ranges){
        auto [l,r] = i;

        
        ans = max(ans, query(rt, 1, N, l, l+p-1));
        ans = max(ans, query(rt, 1, N, r-p+1, r));
    }

    cout << ans << "\n";

    
    
}