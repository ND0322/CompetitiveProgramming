#include <bits/stdc++.h>
#include <iostream>
#include <set>


using namespace std;

#define int long long

const int MAXN = 1e6+5;

int n, k, a[MAXN], b[MAXN], psa[MAXN], st[MAXN<<2];

multiset<int> s;
set<pair<int,int>> vals;


/*
num things where psa[r] - psa[i-1] < 0
psa[r] < psa[i-1]

that can be done with sets and bsearch
-2 -5 - 4
*/

void update(int node, int l, int r, int i){
    if(l == r){
        st[node] = 1;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l, mid, i);
    else update(node<<1|1, mid+1,r,i);
    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return query(node<<1, l, mid, x, y) + query(node<<1|1,mid+1,r,x,y);
}

int32_t main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++){
        psa[i] = psa[i-1] + b[i] - a[i];
        vals.insert({psa[i], i});
    }

    int r = 0;
    int ans = 0;
    int sm = 0;

    vector<pair<int,pair<int,int>>> queries;

    for(int i = 1; i <= n; i++){
        r = max(r, i-1);
        //cout << i << " " << r+1 << " " << sm << " " << k + sm + (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]) << " " << max((s.size() == 0 ? 0 :*s.rbegin()), a[r+1] + (b[r+1] < a[r+1]) * (b[r+1] - a[r+1])) << "\n";

        while(r < n && k + sm + (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]) >= max((s.size() == 0 ? 0 :*s.rbegin()), a[r+1] + (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]))){
            //cout << i << " " <<r+1 << " " << k + sm + (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]) << " " << max((s.size() == 0 ? 0 :*s.rbegin()), a[r+1] - (b[r+1] < a[r+1]) * b[r+1])<< "\n";
            sm += (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]);
            s.insert(a[r+1] + (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]));
            r++;
        }

        ans += max(r-i+1, 0LL);

        if(r >= i) queries.push_back({psa[i-1], {i, r}});

        if(r >= i){
            sm -= (b[i] < a[i]) * (b[i] - a[i]);
            s.erase(s.find(a[i] + (b[i] < a[i]) * (b[i] - a[i])));
        }
    }


    sort(queries.begin(), queries.end());

    for(auto i : queries){
        while(vals.size() && (*vals.begin()).first < i.first){
            update(1,1,n, (*vals.begin()).second);
            vals.erase(vals.begin());
        }

        ans -= query(1,1,n, i.second.first, i.second.second);
    }


    cout << ans << "\n";
}