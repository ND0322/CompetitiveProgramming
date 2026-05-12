#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 4e5+5;

int n, k, a[MAXN], cnt, dp[MAXN][2];
map<int,int> mp;

/*
notice that it is always optimal to apply negative on a prefix or positive on a suffix

I think the range change only effects one transition (from inside to segment to outside)
This is because the prefix is completely the same relative to itself and the first
move out oves us into the second half 

in other words, for exactly one transition query, we instead of query(a[i], 1e9)
we can query(a[i] - x, 1e9)
*/

struct segtree{
    int st[MAXN<<2];

    void update(int node, int l, int r, int i, int x){
        if(l == r){
            st[node] = x;
            return;
        }

        int mid = (l+r)>>1;
        if(i <= mid) update(node<<1, l, mid, i, x);
        else update(node<<1|1, mid+1, r,i,x);
        st[node] = max(st[node<<1], st[node<<1|1]);
    }

    int query(int node, int l, int r, int x, int y){
        if(x > r || y < l) return 0;
        if(x <= l && y >= r) return st[node];
        
        int mid = (l+r)>>1;
        return max(query(node<<1,l ,mid, x, y), query(node<<1|1, mid+1, r, x,y));
    }
} st[2];



int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    set<int> s;

    for(int i = 1; i <= n; i++){
        s.insert(a[i]);
        s.insert(a[i] - k);
    }

    auto it = s.begin();
    int cnt = 1;

    while(it != s.end()){
        mp[*it] = cnt++;
        it++;
    }


    int m = cnt;

    dp[n][0] = 1;
    dp[n][1] = 1;

    st[0].update(1,1,m,mp[a[n]], 1);
    st[1].update(1,1,m,mp[a[n]], 1);

    for(int i = n-1; i >= 1; i--){
        //jump from 0 to 0
        dp[i][0] = st[0].query(1,1,m, mp[a[i]]+1, m);



        //jump from 1 to 1
        dp[i][1] = st[1].query(1,1,m, mp[a[i]]+1, m);

        //jump from 1 to 0
        dp[i][1] = max(dp[i][1], st[0].query(1,1,m, mp[a[i] - k] + 1, m));
        
        dp[i][0]++;
        dp[i][1]++;

        st[0].update(1,1,m, mp[a[i]], dp[i][0]);
        st[1].update(1,1,m, mp[a[i]], dp[i][1]);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) ans = max(ans, dp[i][1]);
    

    cout << ans << "\n";


}