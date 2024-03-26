#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;


/*
either use range set to max(a[i],x) or sort by r and do range set
dif array for range update point query of the other thing
*/

int n, m, dp[MAXN], seg[MAXN<<1];

vector<pair<int,int>> ranges;

void update(int l, int r){
    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) seg[l++]++;
        if(r&1) seg[--r]++;
    }
}

int query(int i){
    int ans = 0;
    for(i += n; i > 0; i>>=1) ans += seg[i];
    return ans;
}
struct Node{
    long long val, lzAdd, lzSet;
    Node(){};
} st[MAXN<<2];

void pushdown(int node, int l, int r){
    int mid = (l+r)>>1;

    if(st[node].lzSet){
        st[node<<1].lzSet = st[node<<1|1].lzSet = st[node].lzSet;
        st[node<<1].val = (mid - l + 1) * st[node].lzSet;
        st[node<<1|1].val = (r-mid) * st[node].lzSet;
        st[node<<1].lzAdd = st[node<<1|1].lzAdd = 0;
        st[node].lzSet = 0;
    }

    else if(st[node].lzAdd){
        if(!st[node<<1].lzSet) st[node<<1].lzAdd += st[node].lzAdd;
        else{
            st[node<<1].lzSet += st[node].lzAdd;
            st[node<<1].lzAdd = 0;
        }

        if(!st[node<<1|1].lzSet) st[node<<1|1].lzAdd += st[node].lzAdd;
        else{
            st[node<<1|1].lzSet += st[node].lzAdd;
            st[node<<1|1].lzAdd = 0;
        }

        st[node<<1].val += (mid-l+1) * st[node].lzAdd;
        st[node<<1|1].val += (r-mid) * st[node].lzAdd;
        st[node].lzAdd = 0;
    }
}

void build(int node, int l, int r){
    st[node].lzAdd = st[node].lzSet = 0;
    

    if(l == r){
        st[node].val = 0;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
    st[node].val = st[node<<1].val + st[node<<1|1].val;

}

void add(int node, int l, int r, int x, int y, long long val){
    if(x > r || y < l) return;

    if(x == l && y == r){
        st[node].val += (r-l+1) * val;
        if(!st[node].lzSet) st[node].lzAdd += val;
        else st[node].lzSet += val;
        return;
    }

    int mid = (l+r)>>1;

    pushdown(node, l, r);
    add(node<<1, l, mid, x, y, val);
    add(node<<1|1, mid+1, r, x, y, val);
    st[node].val = st[node<<1].val + st[node<<1|1].val;
}

void Set(int node, int l, int r, int x, int y, long long val){
    if(x > r || y < l) return;

    if(x <= l && y >= r){
        st[node].val = (r-l+1) * val;
        st[node].lzAdd = 0;
        st[node].lzSet = val;
        return;
    }

    int mid = (l+r)>>1;

    pushdown(node, l, r);
    Set(node<<1, l, mid, x, y, val);
    Set(node<<1|1, mid+1, r, x, y, val);
    st[node].val = st[node<<1].val + st[node<<1|1].val;
}

long long query(int node, int l, int r, int x, int y){
    if(x >r || y < l) return 0;
    if(x <= l && y >= r) return st[node].val;
    int mid = (l+r)>>1;
    pushdown(node, l, r);
    return query(node<<1, l, mid, x, y) + query(node<<1|1, mid+1, r, x , y);
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        for(int i = 1; i <= 2*n; i++) seg[i] = 0;
        Set(1,1,n,1,n,0);
        ranges.clear();

        for(int i = 0; i < m; i++){
            int l, r; cin >> l >> r;

            ranges.push_back({r,l});
            update(l-1,r);
        }

        
        sort(ranges.begin(),ranges.end());

        for(auto [r,l] : ranges) Set(1,1,n,l,r,r);

        dp[n+1] = 0; 
        for(int i = n; i >= 1; i--){
            dp[i] = dp[i+1];

            if(query(i-1)) dp[i] = max(dp[i], dp[query(1,1,n,i,i)+1] + query(i-1));
        }

        cout << dp[1] << "\n";

        


    }
}