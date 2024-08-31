#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,q, c, st[MAXN<<2], a[MAXN];


/*
for some q with a[i] and h[i]

all [a[i]+1, h[i]) is <= max(pref[a[i]])
therefore all [1, h[i]) <= max(pref[a[i]])
sort by increasing h[i]
if theres a blank that isnt a hi then its always good to make it 1
otherwise make it just bigger
after all that if its not possible then -1 because we have no choice but to set to min
we also have to query right for some stuff
query between ai and hi and set the 0 equal to max
1 2 2 3 4 4 1
*/


void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid, i, x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = max(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return max(query(node<<1, l, mid, x,y), query(node<<1|1,mid+1,r,x,y));
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> q >> c;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            update(1,1,n,i,a[i]);
        }

        vector<pair<int,int>> queries;

        while(q--){
            int x,y; cin >> x >> y;
            queries.push_back({y,x});
        }

        sort(queries.begin(), queries.end());

        int i = 1;
        for(auto [x,y] : queries){
            while(i <= x){
                if(a[i] == 0){
                    update(1,1,n, i, 1);
                }
                i++;
            }

            int mx = query(1,1,n, 1, y);
        
            //cout << x << " " << y << " " << mx << " " << query(1,1,n, y+1, x-1) << "\n";
            if(query(1,1,n, 1, y) < query(1,1,n, y+1, x-1)){
                
                for(int i = y; i >= 1;i --){
                    if(!a[i]){
                        update(1,1,n, i, query(1,1,n, y+1, x-1)); 
                        break;
                    }
                }
            }
            else{
                if(a[x]) continue;
                update(1,1,n,x,max(query(1,1,n,x,x), mx+1));
            }
            

            
        }

        while(i <= n){
            if(a[i] == 0) update(1,1,n, i, 1);
            i++;
        }
        
        bool flag = 1;

        for(int i = 1; i <= n; i++) flag &= (query(1,1,n, i,i) <= c);
        for(auto [x,y] : queries) flag &= (query(1,1,n, x,x) > query(1,1,n, 1, y) && query(1,1,n, y+1, x-1) <= query(1,1,n,1,y));
        
        if(flag){
            for(int i = 1; i < n; i++) cout << query(1,1,n, i,i) << " ";
            cout << query(1,1,n, n,n)<< "\n";
        }
        else cout << "-1\n";
    }
}