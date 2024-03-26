#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, pos[MAXN], s[MAXN], ans[MAXN], st[MAXN<<2];
int f(int x, int y){
  return 2 * ceil(abs(pos[x] - pos[y])/(double)(s[x] + s[y])) - (x&1);
}


void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;

    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1,mid+1,r,i,x);

    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;

    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return query(node<<1, l,mid, x,y) + query(node<<1|1,mid+1,r,x,y);
}

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            pos[i] = 0;
            s[i] = 0;
            ans[i] = 0;
        }

        memset(st, 0, sizeof(st));

        for(int i = 1; i <= n; i++) cin >> pos[i];
        for(int i = 1; i <= n; i++){
            cin >> s[i];
            update(1,1,n,i,1);
        }

        for(int i = 1; i < n; i++) pq.push({f(i,i+1), {i,i+1}});

        while(pq.size()){
            int x= pq.top().first;
            auto [l,r] = pq.top().second;

            //cout << x << " " << l << " " << r << "\n";

            pq.pop();

            if(ans[l] || ans[r]) continue;

            ans[l] = x;
            ans[r] = x;
            update(1,1,n,l,0);
            update(1,1,n,r,0);

            int lo = r;
            int hi = n;

            int ans = -1;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(query(1,1,n, r, mid)){
                    ans = mid;
                    hi = mid-1;
                }
                else lo = mid+1;
            }

            if(ans == -1) continue;

            int tmp = ans;

            lo = 1;
            hi = l;

            ans = -1;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(query(1,1,n, mid, l)){
                    ans = mid;
                    lo = mid+1;
                }
                else hi = mid-1;
            }

            if(ans == -1) continue;

            pq.push({f(ans,tmp), {ans,tmp}});
        }

        for(int i = 1; i < n; i++) cout << ans[i] << " ";
        cout << ans[n] << "\n";



    }
}
