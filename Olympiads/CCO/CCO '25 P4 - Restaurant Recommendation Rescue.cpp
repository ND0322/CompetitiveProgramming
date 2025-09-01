#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 5e5+5;

#define int long long

int n, q, a[MAXN];

//just sliding window with segtree?
//there can only ever be one good array
//this some bullshit
//pref >= j-1 for all j
//same as doing pref of ai - 1
//pref >= -1 for all i
//because the -1 will get contributed j times
//we know that there is always an answer from just the previous solution with the sliding window
//find the minimum prefix sum and shift such that that one becomes index 1 as that will be the hardest to satisfy
//naturally everything else will somehow work out



struct Node{
    int ind, sm, mn;
}st[MAXN<<2];


Node pushup(Node l, Node r){
    Node res;
    res.mn = min(l.sm + r.mn, l.mn);
    res.sm = l.sm + r.sm;
    if(l.mn <= l.sm + r.mn) res.ind = l.ind;
    else res.ind = r.ind;
    return res;

}
void build(int node, int l, int r){
    if(l == r){
        st[node].sm = a[l];
        st[node].mn = a[l];
        st[node].ind =l;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l ,mid);
    build(node<<1|1,mid+1,r);
    st[node] = pushup(st[node<<1], st[node<<1|1]);
}

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node].sm = x;
        st[node].mn = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = pushup(st[node<<1], st[node<<1|1]);
}




int32_t main(){
    cin >> n >> q;

    int sm = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sm += a[i];
        a[i]--;
    }

    if(sm != n-1){
        cout << "0 0\n";
        return 0;
    }

    build(1,1,n);

    cout << "1 " << st[1].ind%n << "\n";

    while(q--){
        int x,y; cin >> x >> y;

        x++;
        y++;

        update(1,1, n, x, a[y]);
        update(1,1, n, y, a[x]);

        swap(a[x], a[y]);

        cout << "1 " << st[1].ind % n << "\n";

        
    }

    
    
  
}


/*
1 2 0 0 1
0 2 1 0 1 -> 2 1 0 1 0
0 0 1 2 1 -> 


claim is that cnt is the same after all swaps 
how many unique values 
sqrt(n) unique values

anytime it swaps actual unique values we can just recompute right?

*/