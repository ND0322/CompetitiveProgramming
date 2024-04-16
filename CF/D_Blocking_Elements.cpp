#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;

long long dp[MAXN], a[MAXN], st[MAXN<<2], psa[MAXN];

void build(int node, int l, int r){
    if(l == r){
        cin >> a[l];
        st[node] = a[l];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

void update(int node, int l, int r, int i, long long x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i,x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

long long query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e18;
    if(x <= l && y >= r) return st[node];
    int mid =(l+r)>>1;
    return min(query(node<<1,l,mid, x,y), query(node<<1|1, mid+1,r,x,y));
}


bool can(long long x){
    update(1,1,n+1,n+1, 0);
    for(int i = n; i >= 0; i--){
        
        int lo = i;
        int hi = n;

        int j = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(psa[mid] - psa[i] <= x){
                j = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        dp[i] = query(1,1,n+1,i+1, j+1) + a[i];
        update(1,1,n+1,i,dp[i]);
    
    }
    return dp[0] <= x;
    
}


/*
bool can(int x){
    for(int i = n; i >= 0; i--){
        int sum = 0;
        dp[i] = 1e9;
        for(int j = i+1; j <= n+1; j++){
            dp[i] = min(dp[i], dp[j]);
            sum += a[j];
            if(sum > x) break;
        }
        dp[i] += a[i];
    }

    return dp[0] <= x;
}
*/




int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            psa[i] = psa[i-1] + a[i];
        }

        
        long long lo = 1;
        long long hi = 1e16;

        long long ans = -1;

        while(lo <= hi){
            long long mid = (lo+hi)>>1;

            if(can(mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        cout << ans << "\n";
        
    
        
        
        
        
        
        


    }
}