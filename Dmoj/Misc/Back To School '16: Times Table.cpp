#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 505;
const int MOD = 1e9+7;

int n,m, q;

pair<int,int> dp[MAXN][MAXN];


struct Node
{
	int sum, lz, ap;
    Node(){
        sum = 0;
        lz = 0;
        ap = 0;
    }

} st[MAXN<<2][MAXN];

Node temp, broken;

Node merge(Node l, Node r)
{
	temp.sum = l.sum + r.sum;
	temp.lz = 0;
	temp.lz = 0;
	return temp;
}



void pushdown(int node, int l, int r, int t){
    if(st[node][t].lz){
        st[node][t].sum += (r - l + 1) * st[node][t].lz;

        if(l != r){
            st[node<<1][t].lz += st[node][t].lz;
            st[node<<1|1][t].lz += st[node][t].lz;
        }

        st[node][t].lz = 0;
    }	

    if(st[node][t].ap){
        int mid = (l + r) >> 1;
        st[node][t].sum += ((r - l + 1) * (r - l + 2) / 2) * st[node][t].ap;

        if(l != r){
            st[node<<1][t].ap += st[node][t].ap;
            st[node<<1|1][t].ap += st[node][t].ap;
            st[node<<1|1][t].lz += st[node][t].ap * (mid - l + 1);
        }

        st[node][t].ap = 0;
    }
}

void update(int node, int l, int r, int x, int y, int p, int t){
    pushdown(node, l,r, t);

    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node][t].lz += (l-x) * p;
        st[node][t].ap += p;
        pushdown(node,l,r, t);
        return;
    }

    int mid = (l+r)>>1;
    update(node<<1,l,mid,x,y,p, t);
    update(node<<1|1, mid+1,r,x,y,p, t);
    st[node][t] = merge(st[node<<1][t], st[node<<1|1][t]);
}
	
Node query(int node, int l, int r, int x, int y, int t){
    pushdown(node, l, r, t);
    if(x > r || y < l) return broken;
    if(x <= l && y >= r) return st[node][t];

    int mid = (l+r)>>1;
    return merge(query(node<<1, l, mid, x,y, t), query(node<<1|1, mid+1,r,x,y, t));
}	

void dfs(int x, int y){
    if(x-1 > 0 && query(1,1,m, y,y, x-1).sum > query(1,1,m, y,y, x).sum){
        dfs(x-1,y);
        dp[x][y] = max(dp[x][y], {dp[x-1][y].first+1, (dp[x-1][y].second + query(1,1,m, y,y, x-1).sum) % MOD});
    }
    if(x+1 <= n && query(1,1,m, y,y, x+1).sum > query(1,1,m, y,y, x).sum){
        dfs(x+1,y);
        dp[x][y] = max(dp[x][y], {dp[x+1][y].first+1, (dp[x+1][y].second + query(1,1,m, y,y, x+1).sum) % MOD});
    }
    if(y-1 > 0 && query(1,1,m, y-1,y-1, x).sum > query(1,1,m, y,y, x).sum){
        dfs(x,y-1);
        dp[x][y] = max(dp[x][y], {dp[x][y-1].first+1, (dp[x][y-1].second + query(1,1,m, y-1,y-1, x).sum) % MOD});
    }

    if(y+1 <= m && query(1,1,m, y+1,y+1, x).sum > query(1,1,m, y,y, x).sum){
        dfs(x,y+1);
        dp[x][y] = max(dp[x][y], {dp[x][y+1].first+1, (dp[x][y+1].second + query(1,1,m, y+1,y+1, x).sum % MOD)});
    }
}



int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);

    cin >> m >> n >> q;


    while(q--){
        int x,y,w,h, p; cin >> y >> x >> w >> h >> p;

        for(int i = 0; i < h; i++) update(1,1,m,y, y+w-1,(i+1)*p, (i + x));
    }
    int x,y; cin >> x >> y;

    dfs(y,x);

    cout << dp[y][x].second + query(1,1,m, y,y, x).sum << "\n";

    

}