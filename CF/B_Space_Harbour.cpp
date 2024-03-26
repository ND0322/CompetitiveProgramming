#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e6+5;

int n, q;

using namespace std;

//https://dmoj.ca/problem/acc3p4


struct Node
{
	int sum, lz, ap;
    Node(){
        sum = 0;
        lz = 0;
        ap = 0;
    }

} st[MAXN<<2];

Node temp, broken;

Node merge(Node l, Node r)
{
	temp.sum = l.sum + r.sum;
	temp.lz = 0;
	temp.lz = 0;
	return temp;
}



void pushdown(int node, int l, int r){
    if(st[node].lz){
        st[node].sum += (r - l + 1) * st[node].lz;

        if(l != r){
            st[node<<1].lz += st[node].lz;
            st[node<<1|1].lz += st[node].lz;
        }

        st[node].lz = 0;
    }	

    if(st[node].ap){
        int mid = (l + r) >> 1;
        st[node].sum += ((r - l + 1) * (r - l + 2) / 2) * st[node].ap;

        if(l != r){
            st[node<<1].ap += st[node].ap;
            st[node<<1|1].ap += st[node].ap;
            st[node<<1|1].lz += st[node].ap * (mid - l + 1);
        }

        st[node].ap = 0;
    }
}

void update(int node, int l, int r, int x, int y, int p){
    pushdown(node, l,r);

    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].lz += (l-x) * p;
        st[node].ap += p;
        pushdown(node,l,r);
        return;
    }

    int mid = (l+r)>>1;
    update(node<<1,l,mid,x,y,p);
    update(node<<1|1, mid+1,r,x,y,p);
    st[node] = merge(st[node<<1], st[node<<1|1]);
}
	
Node query(int node, int l, int r, int x, int y){
    pushdown(node, l, r);
    if(x > r || y < l) return broken;

    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return merge(query(node<<1, l, mid, x,y), query(node<<1|1, mid+1,r,x,y));
}	







int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int l,r,x; cin >> l >> r >> x;

            update(1,1,n,l,r,x);
        }
        else{
            int l,r; cin >> l >> r;

            cout << query(1,1,n,l,r).sum << "\n";
        }
    }

}