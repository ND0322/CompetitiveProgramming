inline void update(int node, int l, int r, int i, int x) {
    if(l == r) {
        st[node].sm[0] = x;
        st[node].sm[1] = x;
        return;
    }
    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1, r, i, x);
    
    st[node].sm[0] = (st[node<<1].sm[0] + st[node<<1|1].sm[0]);
    if(st[node].sm[0] >= MOD) st[node].sm[0] -= MOD;
    st[node].sm[1] = (st[node<<1].sm[1] + st[node<<1|1].sm[1]);
    if(st[node].sm[1] >= MOD) st[node].sm[1] -= MOD;
}