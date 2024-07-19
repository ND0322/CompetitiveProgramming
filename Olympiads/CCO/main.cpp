#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5e5+5;
const int MOD = 1e6+3;

int n, a[MAXN], dp[MAXN], st[MAXN<<1][2], nxt[MAXN][2], b[MAXN][2],  val[2][2];

set<pair<int,int>> ranges[2][2], rem;
bool rig[MAXN];

//check all lights first with bsearch
//first point where projected r is less than current r
//then stuff with heavy
//sweep from r to l



void update(int node, int l, int r, int i, int x, bool t){
    if(l == r){
        st[node][t] = x;
        return;
    }

    int mid = (l+r)>>1;

    if(i <= mid) update(node<<1, l, mid, i, x, t);
    else update(node<<1|1, mid+1,r,i,x,t);
    st[node][t] = min(st[node<<1][t], st[node<<1|1][t]);
}

int query(int node, int l, int r, int x, int y, int t){
    if(x > r || y < l) return 1e6;
    if(x <= l && y >= r) return st[node][t];
    int mid = (l+r)>>1;
    return min(query(node<<1,l,mid,x,y,t), query(node<<1|1,mid+1,r,x,y,t));
}

void dfs(int l, int r, bool p, bool i){
    while(ranges[p][i].lower_bound({l,1e6}) != ranges[p][i].end()){
        auto [cr, cl] = *ranges[p][i].lower_bound({l,1e6});
        ranges[p][i].erase(ranges[p][i].lower_bound({l,1e6}));
        rem.insert({cr,cl});
        dfs(cl, cr, p, i);
    }
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) nxt[i][0] = nxt[i][1] = 1e6;

    //0 is matching 1 is opposite
    for(int i = 1; i <= n; i++){
        nxt[b[a[i]][0]][i&1] = i;
        nxt[b[a[i]][1]][!(i&1)] = i;
        if(b[a[i]][0] || b[a[i]][1]) rig[i] = 1;
        b[a[i]][i&1] = i;
    }


    //for light on odd
    //lights are normal
    //even indices query the next thing with opposite parity

    
    for(int i = 1; i <= n; i++){
        if(i&1){
            update(1,1,n,i, min(nxt[i][0],nxt[i][1]), 0);
            update(1,1,n,i, nxt[i][1], 1);
        }
        else{
            update(1,1,n,i, min(nxt[i][0],nxt[i][1]), 1);
            update(1,1,n,i, nxt[i][1], 0);
        }
    }

    //process all odds and evens seperate ish 
    //iterate through for 4 different pointers

    //instead of ranges fined leftmost stuff cause the ranges form intersections anyway

    for(int i = n; i >= 1; i--){
        //light first

        if(nxt[i][0] == 1e6 && rig[i]) ;
        else{
            ranges[i&1][0].insert({nxt[i][0], i});
            ranges[i&1][1].insert({nxt[i][0], i});
        }
        

        int lo = 1;
        int hi = n;

        int r = 1e6;

        

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(query(1,1,n,i, mid, !(i&1))-1 <= mid){
                hi = mid-1;
                r = mid;
            }
            else lo = mid+1;
        }

        cout << i << " " << r << "\n";

        rem.clear();

        while(ranges[i&1][0].lower_bound({r+1, 1e6}) != ranges[i&1][0].end()){
            auto [cr,cl] = *ranges[i&1][0].lower_bound({r+1,1e6});
            dfs(cl,cr,i&1, 0);
        }

        cout << "rem\n";

        for(auto [r,l] : rem) cout << l << " " << r << "\n";

        cout << "erem\n";


    }
}