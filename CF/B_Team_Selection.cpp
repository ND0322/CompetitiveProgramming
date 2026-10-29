#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, k, a[MAXN];


int st[MAXN<<2];

//might have to fractional cascading to not tle


void build(int node, int l, int r){
    if(l == r){
        st[node] = a[l];
        return;
    }

    int mid = (l+r)>>1;

    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = min(st[node<<1], st[node<<1|1]);
}


//largest element >= k
//first element < k
int qr(int node, int l, int r, int x, int y, int k){
    if(l == x && r == y && st[node] >= k) return n+1;
    if(l == r) return l;

    int mid = (l+r)>>1;
    if(y <= mid) return qr(node<<1, l, mid, x, y, k);
    else if(x > mid) return qr(node<<1|1, mid+1, r, x, y, k);
    else{
        int res = qr(node<<1, l , mid,x, mid, k);
        return (res != n+1 ? res :  qr(node<<1|1, mid+1 , r,mid+1, y, k));
    } 
}

int ql(int node, int l, int r, int x, int y, int k){
    if(l == x && r == y && st[node] >= k) return 0;
    if(l == r) return l;

    int mid = (l+r)>>1;
    if(y <= mid) return ql(node<<1, l, mid, x, y, k);
    else if(x > mid) return ql(node<<1|1, mid+1, r, x, y, k);
    else{
        int res = ql(node<<1|1, mid+1 , r,mid+1, y, k);
        return (res != 0 ? res :  ql(node<<1, l , mid,x, mid, k));
    } 
}



int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    build(1,1,n);

    pair<pair<int,int>,pair<int,int>> ans = {{-1,-1}, {-1,-1}};


    for(int i = 1; i <= n; i++){
        //let this be the maximum

        //maximum minimum 

        int lo = 0;
        int hi = a[i];

        int opt = 0;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(qr(1,1,n, i, n, mid) - 1 - i + i - ql(1,1,n, 1, i, mid) >= k){
                lo = mid+1;
                opt = mid;
            }
            else hi = mid-1;
        
        }

        int l = ql(1,1,n, 1, i, opt);
        int r = qr(1,1,n, i, n, opt)-2;
        ans = max(ans, {{a[i] + opt, r-l+1}, {l, r}});
    }
    cout << ans.first.first << " " << ans.second.first << " " << ans.second.second << "\n";
}