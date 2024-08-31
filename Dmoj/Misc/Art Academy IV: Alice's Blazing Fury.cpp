#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5e5;

int n, m, q, tot;
set<pair<int,int>> lr[MAXN<<1];
bool h[MAXN<<2], has[MAXN<<2];
int lz[MAXN<<2], st[MAXN<<2];

//has is checking right endpoints 

void update(int l, int r, int v){
    l += tot;
    r += tot;

    pair<int,int> tmp = {l,r};

    int k = 0;
    for(; (l >> k) > 0; k++);
    for(k -= 2; k >= 0; k--){
        int i = (l>>k);
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

    k = 0;
    for(; (r >> k) > 0; k++);
    for(k -= 2; k >= 0; k--){
        int i = (r>>k);
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

    for(; tmp.first > 1; tmp.first>>=1){
        if(h[tmp.first>>1]) st[tmp.first>>1] = lz[tmp.first>>1];
        else st[tmp.first>>1] = max(st[tmp.first], st[tmp.first^1]);
    }
    for(; tmp.second > 1; tmp.second>>=1){
        if(h[tmp.second>>1]) st[tmp.second>>1] = lz[tmp.second>>1];
        else st[tmp.second>>1] = max(st[tmp.second], st[tmp.second^1]);
    }
    
}

int query(int l, int r){
    l += tot;
    r += tot;

    int k = 0;
    for(; (l >> k) > 0; k++);
    for(k -= 2; k >= 0; k--){
        int i = (l>>k);
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

    k = 0;
    for(; (r >> k) > 0; k++);
    for(k -= 2; k >= 0; k--){
        int i = (r>>k);
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

    int ans = 0;

    for(; l < r; l >>=1, r>>=1){
        if(l&1) ans = max(ans, st[l++]);
        if(r&1) ans = max(ans, st[--r]);
    }

    return ans;
}

int main(){
    scanf("%d %d %d", &n, &m, &q);
    tot = n*m*2;
    

    while(q--){
        int opt, x, y, z; 
        scanf("%d %d %d %d", &opt, &x, &y, &z);

        if(opt == 1){
            for(int i = x; i <= x+z-1; i++){
                int l = y;
                int r = y+z-1;

                int df = m * (i-1);

                if(r+1 <= m && has[df + r+1]){
                    auto it = lr[i].lower_bound({l,r});
                    r = (*it).second;
                    lr[i].erase(it);
                    has[df + r+1] = 0;
                }
                
                if(l != 1 && has[df + l-1]){
                    auto it = lr[i].lower_bound({l,r});

                    it--;
                    l = (*it).first;
                    lr[i].erase(it);
                    has[df+l-1] = 0;
                }

                lr[i].insert({l,r});
                has[df + l] = 1;
                has[df + r] = 1;
                update(df + l,df + r+1, r-l+1);
            }
            for(int i = y; i <= y+z-1; i++){

                int l = x;
                int r = x+z-1;

                int df = n*m + n * (i-1);

                
                if(r+1 <= n && has[df + r+1]){
                    auto it = lr[i].lower_bound({l,r});
                    r = (*it).second;
                    lr[i].erase(it);
                    has[df + r+1] = 0;
                }
                
                if(l != 1 && has[df + l-1]){
                    auto it = lr[i].lower_bound({l,r});

                    it--;
                    l = (*it).first;
                    lr[i].erase(it);
                    has[df+l-1] = 0;
                }

                lr[i].insert({l,r});
                has[df + l] = 1;
                has[df + r] = 1;
                update(df + l,df + r+1, r-l+1);
            }

            continue;
        }

        if(opt == 2){
            for(int i = x; i <= x+z-1; i++){
                int l = y;
                int r = y+z-1; 

                int df = m * (i-1);

                auto it = lr[i].lower_bound({l+1,r});
                it--;

                auto [sl, sr] = *it;
                lr[i].erase(it);

                
                update(df + l, df + r+1, 0);
                if(l != sl){
                    lr[i].insert({sl, l-1});
                    has[df + l-1] = 1;
                }
                else has[df + sl] = 0;
                if(r != sr){
                    lr[i].insert({r+1, sr});
                    has[df + r + 1] = 1;
                }
                else has[df+sr] = 0;
                
                update(df + sl, df + l, l-sl);
                update(df + r+1, df + sr+1, sr - r);
            }

            for(int i = y; i <= y+z-1; i++){
                int l = x;
                int r = x+z-1; 

                int df = n*m + n * (i-1);

                auto it = lr[i].lower_bound({l+1,r});
                it--;

                auto [sl, sr] = *it;
                lr[i].erase(it);

                
                update(df + l, df + r+1, 0);
                if(l != sl){
                    lr[i].insert({sl, l-1});
                    has[df + l-1] = 1;
                }
                else has[df + sl] = 0;
                if(r != sr){
                    lr[i].insert({r+1, sr});
                    has[df + r + 1] = 1;
                }
                else has[df+sr] = 0;
                
                update(df + sl, df + l, l-sl);
                update(df + r+1, df + sr+1, sr - r);
            }

            continue;
        }
        if(opt == 3){
            int ans = 0;
            for(int i = x; i <= x+z-1; i++){
                ans = max(ans, query((i-1) * m + y,(i-1) * m + y+z));
                if(ans == m) break;
            }
            for(int i = y; i <= y+z-1; i++){
                ans = max(ans, query(n * m + n * (i-1) + x,n * m + n * (i-1) + x+z));
                if(ans == n) break;
            }
            printf("%d\n", ans);
        }
    }


}