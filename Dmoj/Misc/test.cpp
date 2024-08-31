
bool h[MAXN<<2][2];
int lz[MAXN<<2][2], st[MAXN<<2][2], rr[MAXN<<1];


inline void push(int i, bool t) {

    if(h[i>>1]){
        st[i][t] = lz[i>>1][t];
        lz[i][t] = lz[i>>1][t];
        h[i][t] = 1;
        st[i^1][t] = lz[i>>1][t];
        lz[i^1][t] = lz[i>>1][t];
        h[i^1][t] = 1;
        h[i>>1][t] = 0;
    }
}

inline void pushdown(int i, bool t){
    int k = 0;
    for(; (i >> k) > 0; k++);
    for(k -= 2; k >= 0; k--) push(i>>k, t);
}

inline void pop(int i, bool t){
    if(h[i>>1][t]) st[i>>1][t] = lz[i>>1][t];
    else st[i>>1][t] = max(st[i][t], st[i^1][t]);
}

inline void popup(int i, bool t){
    for(; i > 1; i>>=1) pop(i, t);
}

inline void update(int l, int r, int v, bool t){
    l += tot;
    r += tot;

    pair<int,int> tmp = {l,r};

    pushdown(l, t);
    pushdown(r, t);

    for(; l < r; l >>=1, r>>=1){
        if(l&1){
            st[l][t] = v;
            lz[l][t] = v;
            h[l][t] = 1;
            l++;
        }
        if(r&1){
            r--;
            st[r][t] = v;
            lz[r][t] = v;
            h[r][t] = 1;
        }
    }

    popup(tmp.first, t);
    popup(tmp.second, t);
}

inline int query(int l, int r, bool t){
    l += tot;
    r += tot;

    pushdown(l, t);
    pushdown(r,t );

    int ans = 0;

    for(; l < r; l >>=1, r>>=1){
        if(l&1) ans = max(ans, st[l++][t]);
        if(r&1) ans = max(ans, st[--r][t]);
            
    }

    return ans;
}