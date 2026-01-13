#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long


/*
sum of times - n * smallest a, n-1 * second smallest 

when updating the a value from bigger to smaller it will move earlier in the list
everything between its old and new position must shift right ie - 1 for each product
so subtract the whole sum

we can do this by building segtree over a values and querying the sum of elements between old and new a values
*/

int n, q,m, st[MAXN<<2], cnt[MAXN<<2], b[MAXN], a[MAXN], sm;

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] += x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1, r,i,x);
    st[node] = st[node<<1] + st[node<<1|1];
}

void add(int node, int l, int r, int i, int x){
    if(l == r){
        cnt[node] += x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) add(node<<1, l, mid, i, x);
    else add(node<<1|1, mid+1, r,i,x);
    cnt[node] = cnt[node<<1] + cnt[node<<1|1];
}


int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return query(node<<1, l, mid, x, y) + query(node<<1|1, mid+1, r, x, y);
}

int qcnt(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return cnt[node];

    int mid = (l+r)>>1;
    return qcnt(node<<1, l, mid, x, y) + qcnt(node<<1|1, mid+1, r, x, y);
}


int32_t main(){
    cin >> n >> q;

    vector<int> tmp(n+1);
    for(int i = 1; i <= n; i++){
        cin >> b[i] >> a[i];

        tmp[i] = a[i];

        sm += b[i];
    }


    sort(tmp.begin(), tmp.end());
    m = 2e5;

    int penalty = 0;
    for(int i = 1; i <= n; i++){
        penalty += (n-i+1) * tmp[i];
        update(1,1,m, a[i], a[i]);
        add(1,1,m, a[i], 1);
    }
    
    cout << sm - penalty << "\n";

    while(q--){
        int i, y, x; cin >> i >> y >> x;

        sm -= b[i];
        b[i] = y;
        sm += b[i];

        if(a[i] < x){

            //take rightmost and move to leftmost

            int shift = query(1,1,m, min(a[i], x)+1, max(a[i], x)-1);
            int old = qcnt(1,1,m, 1, a[i]) - 1;

            add(1,1,m, a[i], -1);
            add(1,1,m, x, 1);
            
            int nw = qcnt(1,1,m, 1, x-1);
            

            penalty -= a[i] * (n-old);
            penalty += x * (n - nw);
            penalty += shift;
        }
        else if(a[i] > x){
            //take leftmost and move to rightmost
            int shift = query(1,1,m, min(a[i], x)+1, max(a[i], x)-1);
            int old = qcnt(1,1,m, 1, a[i]-1);
            add(1,1,m, a[i], -1);
            add(1,1,m, x, 1);
            int nw = qcnt(1,1,m, 1, x) - 1;

            penalty -= a[i] * (n-old);
            penalty += x * (n - nw);
            penalty -= shift;
        }

        

        
        

        update(1,1,m, a[i], -a[i]);
        a[i] = x;
        update(1,1,m, a[i], a[i]);
        

        cout << sm - penalty << "\n";
       

    }
}