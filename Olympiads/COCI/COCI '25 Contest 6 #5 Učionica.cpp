#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n,m,k, a[MAXN][MAXN], b[MAXN], pmax[MAXN][MAXN];

struct Node{
    int lz = 0;
    int mn = 0;
} st[MAXN<<2];

/*
every time we move rows set each i to max(st[i], a[j][i])
prefix maxes on columns to do that part 


Add the first window of K and determine if an answer exists in o(k)

When we slide we remove one element in the set and add a new one on the right so we can binary search for the 

Sort the k by decreasing, the each item in our window has a maximum r that it can have
lets keep track of the frequency of each r value 
We need to find any r < pmax[r]
If we keep in the segtree the initial value of r - pmax[r] 
Every time we add/remove an item it will be a suffix update
*/

void pushdown(int node, int l, int r){
    if(!st[node].lz) return;

    st[node<<1].lz += st[node].lz;
    st[node<<1|1].lz += st[node].lz;
    st[node<<1].mn += st[node].lz;
    st[node<<1|1].mn += st[node].lz;

    st[node].lz = 0;
}

void update(int node, int l, int r, int x, int y, int v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn += v;
        st[node].lz += v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r);
    update(node<<1, l, mid, x, y, v);
    update(node<<1|1, mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e9;
    if(x <= l && y >= r) return st[node].mn;

    int mid = (l+r)>>1;
    pushdown(node, l, r);
    return min(query(node<<1, l, mid, x,y), query(node<<1|1, mid+1, r, x, y));
}




int main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= k; i++) cin >> b[i];

    sort(b+1, b+k+1);
    reverse(b+1, b+k+1);

    b[0] = 1e9;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }

    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++) pmax[i][j] = max(a[i][j], pmax[i-1][j]);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        set<int> s;

        for(int j = 1; j <= k; j++) update(1,1,k, j,j, -query(1,1,k, j, j) + j);


        for(int j = 1; j < k; j++){

            if(a[i][j]){
                s.insert(j);
                continue;
            }
            int lo = 0;
            int hi = k;

            int r = 0;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(b[mid] > pmax[i-1][j]){
                    r = mid;
                    lo = mid+1;
                }
                else hi = mid-1;
            }

            if(!r) s.insert(j);
            else update(1,1,k, r, k, -1);
            
        }

        for(int j = k; j <= m; j++){
            if(a[i][j]) s.insert(a[i][j]);
            
            int lo = 0;
            int hi = k;

            int r = 0;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                //cout << mid << " " << b[mid] << " " << pmax[i-1][j] << "\n";

                if(b[mid] > pmax[i-1][j]){
                    r = mid;
                    lo = mid+1;
                }
                else hi = mid-1;
            }

            if(!r) s.insert(j);

            if(s.find(j) == s.end()) update(1,1,k, r, k, -1);

            if(!s.size()) ans += query(1,1,k, 1, k) >= 0;

            int l = j - k + 1;

            if(s.find(l) == s.end()){
                lo = 0;
                hi = k;

                r = 0;

                while(lo <= hi){
                    int mid = (lo+hi)>>1;

                    if(b[mid] > pmax[i-1][l]){
                        r = mid;
                        lo = mid+1;
                    }
                    else hi = mid-1;
                }

                update(1,1,k, r, k, 1);
            }
            else s.erase(l);
        }


    }

    cout << ans << "\n";



}