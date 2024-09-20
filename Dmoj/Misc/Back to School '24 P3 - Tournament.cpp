#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long

const int MAXN = 3e5+5;

int n, a[MAXN];

pair<int,int> st[MAXN<<2];

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node].first = 0;
        st[node].second = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1, r, i, x);
    st[node].first = abs(st[node<<1].second - st[node<<1|1].second) * abs(st[node<<1].second - st[node<<1|1].second) + st[node<<1].first + st[node<<1|1].first;
    st[node].second = max(st[node<<1].second, st[node<<1|1].second);
}



int32_t main(){
    cin >> n;
    
    for(int i = 2; i <= n; i++) cin >> a[i];

    set<int> s;

    for(int i = 1; i <= n; i++) s.insert(i);

    

    for(int i = 2; i <= n; i++){
        update(1,1,n, i, a[i]);
        s.erase(a[i]);
    }

    int k = *s.begin();

    update(1,1,n, 1, k);

    cout << st[1].first << " ";

    int p = 1;

    for(int i = 2; i <= n; i++){
        update(1, 1, n, p, a[i]);
        update(1,1,n, i, k);
        p++;
        cout << st[1].first << " ";
    }

    cout << "\n";
}