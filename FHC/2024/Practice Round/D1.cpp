#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e6+5;

//increment from 0 to x
//when we create a new stone just reset that pos to - number of stones before me

//use ulimit -s unlimited

struct Node{
    long long mn, mx, sum, lzAdd, lzSet;
    Node(){};
} st[MAXN<<2];

int ts[MAXN<<2];

void pushdown(int node, int l, int r, int mid){
    if(st[node].lzSet){
        st[node<<1].lzSet = st[node<<1|1].lzSet = st[node].lzSet;
        st[node<<1].lzAdd = st[node<<1|1].lzAdd = 0;
        st[node<<1].mn = st[node<<1|1].mn = st[node].lzSet;
        st[node<<1].mx = st[node<<1|1].mx = st[node].lzSet;

        if(l != r){
            st[node<<1].sum = st[node].lzSet * (mid-l+1);
            st[node<<1|1].sum = st[node].lzSet * (r-mid);
        }
        
    }

    if(st[node].lzAdd){
        st[node<<1].lzAdd += st[node].lzAdd;
        st[node<<1|1].lzAdd += st[node].lzAdd;
        st[node<<1].mn += st[node].lzAdd;
        st[node<<1|1].mn += st[node].lzAdd;
        st[node<<1].mx += st[node].lzAdd;
        st[node<<1|1].mx += st[node].lzAdd;
        if(l != r){
            st[node<<1].sum += st[node].lzAdd * (mid-l+1);
            st[node<<1|1].sum += st[node].lzAdd * (r-mid);
        }
    }

    st[node].lzAdd = st[node].lzSet = 0;
}


void add(int node, int l, int r, int x, int y, long long v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn += v;
        st[node].mx += v;
        st[node].sum += (r-l+1)*v;
        st[node].lzAdd += v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    add(node<<1, l, mid, x, y, v);
    add(node<<1|1, mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

void update(int node, int l, int r, int x, int y, long long v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn = v;
        st[node].mx = v;
        st[node].sum = (r-l+1)*v;
        st[node].lzAdd = 0;
        st[node].lzSet = v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    update(node<<1,l,mid,x,y,v);
    update(node<<1|1,mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

long long qmn(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e18;
    if(x <= l && y >= r) return st[node].mn;
    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    return min(qmn(node<<1, l, mid, x,y), qmn(node<<1|1,mid+1,r,x,y));
}

long long qmx(int node, int l, int r, int x, int y){
    if(x > r || y < l) return -1e18;
    if(x <= l && y >= r) return st[node].mx;
    int mid = (l+r)>>1;
    pushdown(node,l, r, mid);
    return max(qmx(node<<1,l,mid,x,y), qmx(node<<1|1,mid+1,r,x,y));
}

long long qsm(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sum;
    int mid = (l+r)>>1;
    pushdown(node,l,r,mid);
    return qsm(node<<1,l,mid,x,y) + qsm(node<<1|1,mid+1,r,x,y);
}

void build(int node, int l,int r){
    if(l == r){
        ts[node] = 0;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
    ts[node] = ts[node<<1] + ts[node<<1|1];
}

void ins(int node, int l, int r, int i){
    if(l == r){
        ts[node] = 1;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) ins(node<<1, l, mid, i);
    else ins(node<<1|1, mid+1, r, i);
    ts[node] = ts[node<<1] + ts[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return ts[node];

    int mid = (l+r)>>1;

    return query(node<<1, l, mid, x,y) + query(node<<1|1, mid+1,r, x,y); 
}



int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n, k; cin >> n >> k;

        vector<pair<int,int>> a(n+1);

        set<int> s;

        update(1,1,1e6,0, 1e6, 0);
        build(1,1,1e6);

        for(int i = 1; i <= n; i++){
            cin >> a[i].first;
            a[i].second = i;

            s.insert(a[i].first);
            
            


            add(1,1, 1e6, 1, a[i].first, 1);
            update(1,1,1e6, a[i].first, a[i].first, -query(1, 1, 1e6, 1, a[i].first));
            ins(1,1, 1e6, a[i].first);
        }

        sort(a.begin(), a.end());

        pair<int,int> ans = {1e9, -1};

        for(int i = 1; i <= n; i++){
            int dist = abs(k - a[i + qsm(1, 1, 1e6, a[i].first,a[i].first)].first);

            ans = min(ans, {dist, a[i].second});
        }        


        cout << "Case #" << _ << ": " << ans.second << " " << ans.first << "\n";
    }
}

