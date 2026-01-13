#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2505;
const int MAXM = 2e5+5;

/*
precompute for each cell the number of colors that they contain at least one of
do this with PIE and difference array

segtree over the number of shells in each grid
query is a suffix sum

updates subtract 1 from the grids it affects
n^2 is just check every cell affected by the egg
build dsu on each row and have it point to the next available/rightmost element in the set 
for each one we just continue to look at sets that have not been touched 
should amortize to o(n) for each row
*/


int n,k, m, parents[MAXN][MAXN], r[MAXN][MAXN], st[MAXM<<2], diff[MAXN][MAXN];

bool rem[MAXN][MAXN];


int find(int row, int x){
    while(x != parents[row][x]){
        parents[row][x] = parents[row][parents[row][x]];
        x = parents[row][x];
    }
    return x;
}

bool uni(int row, int x, int y){
    x = find(row, x);
    y = find(row, y);

    if(x == y) return 0;
    parents[row][x] = y;
    r[row][y] = max(r[row][x],r[row][y]);
    return 1;
}

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] += x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid, i, x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;

    return query(node<<1, l, mid, x, y) + query(node<<1|1, mid+1,r,x,y);
}

void add(int x1, int y1, int x2, int y2, int v){
    diff[x1][y1] += v;
    diff[x2+1][y1] -= v;
    diff[x1][y2+1] -= v;
    diff[x2+1][y2+1] += v;
}


int main(){
    cin >> n >> k;

    k--;

    cin >> m;

    for(int i = 1; i <= m; i++){
        int l; cin >> l;

        vector<pair<int,int>> shells;

        for(int j = 1; j <= l; j++){
            int x,y; cin >> x >> y;

            shells.push_back({x,y});
        }

        for(int mask = 1; mask < 1<<l; mask++){

            int tlx = 0;
            int tly = 0;
            int brx = 1e9;
            int bry = 1e9;
            for(int j = 0; j < l; j++){
                if(mask & (1<<j)){
                    tlx = max(tlx, shells[j].first);
                    tly = max(tly, shells[j].second);
                    brx = min(brx, shells[j].first);
                    bry = min(bry, shells[j].second);
                }
            }

            tlx -= k;
            tly -= k;


            tlx = max(tlx, 1);
            tly = max(tly, 1);
            brx = min(brx, n-k);
            bry = min(bry, n-k);
            if(tlx > brx || tly > bry) continue;

            add(tlx, tly, brx, bry, pow(-1, !(__builtin_popcount(mask) & 1)));
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) diff[i][j] += diff[i-1][j];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) diff[i][j] += diff[i][j-1];
    }

    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << diff[i][j] << " ";
        cout << "\n";
    }

    */
    double tot = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            parents[i][j] = j;
            r[i][j] = j;
            update(1,1,m, diff[i][j], 1);

            if(i + k <= n && j + k <= n) tot++;
        }
    }

    

    int q; cin >> q;
    int cnt = 0;
    while(q--){
    
        int t; cin >> t;

        if(t == 1){
            int x, y; cin >> x >> y;
            
            for(int i = max(x-k, 1); i <= min(x, n-k); i++){
                int ty = max(y-k, 1);

                while(ty <= min(y, n-k)){
                    if(!rem[i][ty]){
                        rem[i][ty] = 1;
                        update(1,1,m, diff[i][ty], -1);
                        diff[i][ty] = -1;
                    }

                    if(ty > 1 && rem[i][ty-1]) uni(i, ty-1, ty);  
                    ty = r[i][find(i, ty)]+1;
                }
            }
            
            

            
        }
        else{
            int x; cin >> x;

            //calculate tot

            cout << setprecision(5) << fixed << query(1,1,m, x, m) / tot << "\n";
            
        }

        //for(int i = 1; i <= n; i++){
            //for(int j = 1; j <= n; j++) cout << diff[i][j] << " ";
            //cout << "\n";
        //}

        

       
    }




    
}