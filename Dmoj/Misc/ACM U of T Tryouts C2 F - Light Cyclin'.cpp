#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

#define int long long

int st[MAXN<<2];

//some linesweep bs
//x <= 1e12
//y <= 1e6
//query vertical lines 
//handle removals before queries 

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] += x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return query(node<<1,l,mid,x,y) + query(node<<1|1,mid+1,r,x,y);
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        string trash; cin >> trash;

        vector<pair<pair<int,int>,pair<int,int>>> queries;
        for(int i = 0; i < 2; i++){

        
            int x,y,q, k; cin >> x >> y >> q;
            char c;
            while(q--){
                cin >> c;

                cin >> k;

                if(c == 'L'){
                    queries.push_back({{x-k, 1}, {y, 0}});
                    queries.push_back({{x, -1}, {y, 0}});
                    x -= k;
                }

                if(c == 'R'){
                    queries.push_back({{x, 1}, {y, 0}});
                    queries.push_back({{x+k, -1}, {y, 0}});
                    x += k;
                }

                if(c == 'U'){
                    //l opt r
                    queries.push_back({{x, 0}, {y, y+k}});
                    y += k;
                }

                if(c == 'D'){
                    queries.push_back({{x, 0}, {y-k, y}});
                    y -= k;
                }
            }
        }

        sort(queries.begin(), queries.end());
        long long ans = 0;
        for(auto i : queries){
            int op = i.first.second;
            int x = i.first.first;

            if(!op) ans += query(1,1,1e6, i.second.first, i.second.second);
            else update(1,1,1e6,i.second.first, op);
        }

        cout << ans << "\n";
    }
}