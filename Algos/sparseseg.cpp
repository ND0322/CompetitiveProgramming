#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4e5+5;



typedef long long ll;
//https://dmoj.ca/problem/levvesegtree

int cnt = 1, tr[MAXN*64][2];

ll st[MAXN*64],mx[MAXN*64];

void update(int node, ll l, ll r, ll i, ll x){
    if(l == r){
        st[node] = x;
        mx[node] = x;        
        return;
    }

    ll mid = (l+r)>>1;

    if(i <= mid){
        if(!tr[node][0]) tr[node][0] = ++cnt;
        update(tr[node][0], l,mid,i,x);
    }
    else{
        if(!tr[node][1]) tr[node][1] = ++cnt;
        update(tr[node][1],mid+1,r,i,x);
    }

    st[node] = st[tr[node][0]] + st[tr[node][1]];
    mx[node] = max(mx[tr[node][0]], mx[tr[node][1]]);
}

ll query(int node, ll l, ll r, ll x, ll y){
    if(x > r || y < l) return 0;

    if(x <= l && y >= r) return st[node];
    ll mid = (l+r)>>1;
    return query(tr[node][0],l,mid,x,y) + query(tr[node][1], mid+1,r,x,y);
}

int querym(int node, ll l, ll r, ll x, ll y){
    if(x > r || y < l) return 0;

    if(x <= l && y >= r) return mx[node];
    ll mid = (l+r)>>1;
    return max(querym(tr[node][0],l,mid,x,y),querym(tr[node][1], mid+1,r,x,y));
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    ll n; cin >> n;
    int q; cin >> q;

    ll c = 0;

    while(q--){
        char t; cin >> t;

        if(t == 'C'){
            ll i; cin >> i;
            ll x; cin >> x;

            i ^= c;
            x ^= c;

            update(1,1,n,i,x);
        }

        if(t == 'S'){
            ll l,r; cin >> l >> r;

            l ^= c;
            r ^= c;
            c = query(1,1,n,l,r);
            cout << c << "\n";
        }

        if(t == 'M'){
            ll l,r; cin >> l >> r;

            l ^= c;
            r ^= c;
            c = querym(1,1,n,l,r);
        
            cout << c << "\n";
        }
    }

}