#include <bits/stdc++.h>
#include <iostream>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;

const int MAXN = 2e5+5;



int n, r, k, req[MAXN], freq[MAXN], st[MAXN<<2], a[MAXN];


//recursive cause i need to practice the impl
//a little bit overkill

void update(int node, int l, int r, int i, bool x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1, mid+1,r, i, x);
    st[node] = st[node<<1] + st[node<<1|1];
}


bool can(int x){
    memset(st, 0, sizeof(st));
    memset(freq,0,sizeof(freq));

    for(int i = 1; i <= x; i++) freq[a[i]]++;
    for(int i = 1; i <= k; i++) update(1,1,n,i,freq[i] >= req[i]);

    
    if(st[1] == k) return 1;

    for(int i = x+1; i <= n; i++){
        freq[a[i-x]]--;
        freq[a[i]]++;
        if(freq[a[i-x]] < req[a[i-x]]) update(1,1,n, a[i-x], 0);
        if(freq[a[i]] >= req[a[i]]) update(1,1,n,a[i], 1);
         
    

        if(st[1] == k) return 1;
    }

    return 0;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k >> r;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i]++;
    }

    while(r--){
        int x,y; cin >> x >> y;
        req[x+1] += y;
    }

    int lo = 1;
    int hi = n;
    int ans = -1;
    



    
    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    if(ans == -1) cout << "impossible\n";
    else cout << ans << "\n";
    

    
}