#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 3e5+5;

 
int rr[MAXN][2], st[MAXN<<2][2];

stack<pair<int,int>> stk[2];

void build(int node, int l, int r){
    if(l == r){
        st[node][0] = rr[l][0]; 
        st[node][1] = rr[l][1];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
    st[node][0] = min(st[node<<1][0], st[node<<1|1][0]);
    st[node][1] = min(st[node<<1][1], st[node<<1|1][1]);
}

int query(int node, int l, int r, int x, int y, bool t){
    if(x > r || y < l) return 1e9;
    if(x <= l && y >= r) return st[node][t];
    int mid = (l+r)>>1;
    return min(query(node<<1, l, mid, x,y,t), query(node<<1|1, mid+1, r, x, y, t));
}



int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        while(stk[0].size()) stk[0].pop();
        while(stk[1].size()) stk[1].pop();

        for(int i = 1; i <= n; i++) cin >> a[i];
        stk[0].push({0,1e9});
        stk[1].push({1e9,1e9});
        for(int i = n; i >= 1; i--){
            while(stk[0].size() && stk[0].top().first > a[i]) stk[0].pop();
            while(stk[1].size() && stk[1].top().first < a[i]) stk[1].pop();


            //0 is next smaller 
            rr[i][0] = stk[0].top().second;
            rr[i][1] = stk[1].top().second;
            stk[0].push({a[i], i});
            stk[1].push({a[i], i});
        }

        
        build(1,1,n);
    
        int i = 1;
        int ans = 0;

        while(i < n){
            int lo = i+1;
            int hi = n;
            int nxt = -1;


            while(lo <= hi){
                int mid = (lo+hi)>>1;

                
                if(query(1,1,n, i, mid, 0) >= mid){
                    lo = mid+1;
                    nxt = mid;
                }
                else hi = mid-1;
            }

            

            lo = i+1;
            hi = n;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                cout << mid << " " << query(1,1,n, i, mid, 1) << "\n";

                if(query(1,1,n, i, mid, 1) >= mid){
                    lo = mid+1;
                    nxt = max(nxt,mid);
                }
                else hi = mid-1;
            }

            

            //cout << nxt << " " << query(1,1,n, 1, nxt, 0) << " " << query(1,1,n, 1, nxt, 0) << "\n";

            cout << i << "\n";
            i = nxt;
            ans++;


        }

        cout << ans << "\n";
        

        
    }
}