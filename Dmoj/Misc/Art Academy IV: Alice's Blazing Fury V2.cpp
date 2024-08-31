#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 5e5+1;

int n, m, q, tot, lz[MAXN<<3], st[MAXN<<3], rr[MAXN<<1], opt, z, x[2], df[MAXN][2];



bool h[MAXN<<3];

inline void push(int i) {

    if(h[i>>1]){
        st[i] = lz[i>>1];
        lz[i] = lz[i>>1];
        h[i] = 1;
        st[i^1] = lz[i>>1];
        lz[i^1] = lz[i>>1];
        h[i^1] = 1;
        h[i>>1] = 0;
    }
}

inline void pushdown(int i){
    int k = 0;
    for(; (i >> k) > 0; k++);
    for(k -= 2; k >= 0; k--) push(i>>k);
}

inline void pop(int i){
    if(h[i>>1]) st[i>>1] = lz[i>>1];
    else st[i>>1] = max(st[i], st[i^1]);
}

inline void popup(int i){
    for(; i > 1; i>>=1) pop(i);
}

inline void update(int l, int r, int v){
    l += tot;
    r += tot;

    pair<int,int> tmp = {l,r};

    pushdown(l);
    pushdown(r);

    for(; l < r; l >>=1, r>>=1){
        if(l&1){
            st[l] = v;
            lz[l] = v;
            h[l] = 1;
            l++;
        }
        if(r&1){
            r--;
            st[r] = v;
            lz[r] = v;
            h[r] = 1;
        }
    }

    popup(tmp.first);
    popup(tmp.second);
}

inline int query(int l, int r){
    l += tot;
    r += tot;

    pushdown(l);
    pushdown(r);

    int ans = 0;

    for(; l < r; l >>=1, r>>=1){
        if(l&1) ans = max(ans, st[l++]);
        if(r&1) ans = max(ans, st[--r]);
    }

    return ans;
}
int main(){
    scanf("%d %d %d", &n, &m, &q);

    tot = n*m*4;    

    for(int i = 1; i <= n; i++) df[i][0] = m * (i-1);
    for(int i = 1; i <= m; i++) df[i][1] = n*m + n * (i-1);

    while(q--){

        scanf("%d %d %d %d", &opt, &x[0], &x[1], &z);

        if(opt == 1){
            for(int j = 0; j < 2; j++){
                for(int i = x[j]; i <= x[j]+z-1; i++){
                    int l = x[!j];
                    int r = l+z-1;

                    int dt = df[i][j] + n*m*2; 

                    if(l != 1){
                        int ll = query(dt + l-1,dt+l);
                        if(ll) l = ll;
                    }
                    if(r+1 <= (j ? n : m) && rr[df[i][j] + r+1]){
                        r = rr[df[i][j] + r+1];
                        rr[df[i][j] + r+1] = 0;
                    }

                    update(dt+l, dt+r+1, l);
                    rr[df[i][j] + l] = r;
                    update(df[i][j] + l,df[i][j] + r+1, r-l+1);
                }
            }
            
            continue;
        }

        if(opt == 2){
            for(int j = 0; j < 2; j++){
                for(int i = x[j]; i <= x[j]+z-1; i++){
                    int l = x[!j];
                    int r = l+z-1; 

                    int dt = df[i][j] + 2*n*m;

                    update(df[i][j] + l, df[i][j] + r+1, 0);

                    int sl = query(dt+l,dt+l+1);
                    int sr = rr[df[i][j] + sl];

                    if(sl != l)rr[df[i][j] + sl] = l-1;
                    else rr[df[i][j]+sl] = 0;
                    if(r != sr && r < (j ? n : m)){
                        rr[df[i][j] + r+1] = sr;
                        update(dt+r+1, dt+sr+1, r+1);
                    }
                    else rr[df[i][j]+r+1] = 0;
        
                    update(dt+l, dt+r+1, 0);
                    update(df[i][j] + sl, df[i][j] + l, l-sl);
                    update(df[i][j] + r+1, df[i][j] + sr+1, sr - r);
                }
            }

            continue;
        
        }
        if(opt == 3){
            int ans = 0;
            for(int j = 0; j < 2; j++){
                for(int i = x[j]; i <= x[j]+z-1; i++){
                    ans = max(ans, query(df[i][j] + x[!j],df[i][j] + x[!j]+z));
                    if(ans == (j ? n : m)) break;
                }
            }
            printf("%d\n", ans);
        }
    }


}