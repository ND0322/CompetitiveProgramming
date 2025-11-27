#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//find next with monotnic stack
//for second half either transition to equal
//add 2 ^ length
//coord compress
//range multiply by 2


const int MAXN = 5005;
const int MOD = 998244353;

#define int long long


int dp[MAXN][2];

struct SegTree{
    struct Node{
        int lzA = 0, lzM = 1, val = 0;

    } st[MAXN<<2];

   
    void pushdown(int node, int l, int r){
        int mid = (l+r)>>1;
        
        if(l != r){
            st[node<<1].val = (st[node<<1].val * st[node].lzM % MOD + (mid - l + 1) * st[node].lzA % MOD) % MOD;
            st[node<<1|1].val = (st[node<<1|1].val * st[node].lzM % MOD + (r - mid) * st[node].lzA % MOD) % MOD;
        }
        st[node<<1].lzM = (st[node<<1].lzM * st[node].lzM) % MOD;
        st[node<<1|1].lzM = (st[node<<1|1].lzM * st[node].lzM) % MOD;
        st[node<<1].lzA = ((st[node<<1].lzA * st[node].lzM)%MOD + st[node].lzA) % MOD;
        st[node<<1|1].lzA = ((st[node<<1|1].lzA * st[node].lzM)%MOD + st[node].lzA) % MOD;

        
       
        st[node].lzA = 0;
        st[node].lzM = 1;
    }

    void add(int node, int l, int r, int x, int y, int v){
        if(x > r || y < l) return;
        if(x <= l && y >= r){
            st[node].lzA = (st[node].lzA + v) % MOD;
            st[node].val = (st[node].val + ((r - l + 1) * v) % MOD) % MOD;
            return;
        }

        int mid = (l+r)>>1;
        pushdown(node,l,r);
        add(node<<1, l, mid, x, y, v);
        add(node<<1|1, mid+1,r,x,y,v);
        st[node].val = (st[node<<1].val + st[node<<1|1].val) % MOD;
    }

    void mult(int node, int l, int r, int x, int y, int v){
        if(x > r || y < l) return;
        if(x <= l && y >= r){
            st[node].lzM = (st[node].lzM * v) % MOD;
            st[node].lzA = (st[node].lzA * v) % MOD;
            st[node].val = (st[node].val * v) % MOD;
            return;
        }

        int mid = (l+r)>>1;
        pushdown(node,l,r);
        mult(node<<1, l, mid ,x,y,v);
        mult(node<<1|1, mid+1,r,x,y,v);
        st[node].val = (st[node<<1].val + st[node<<1|1].val) % MOD;
    }

    int query(int node, int l, int r, int x, int y){
        if(x > r || y < l) return 0;
        if(x <= l && y >= r) return st[node].val;
        int mid = (l+r)>>1;
        pushdown(node, l, r);
        return (query(node<<1, l, mid, x, y) + query(node<<1|1, mid+1,r,x,y)) % MOD;
    }

};



int binpow(int a, int b){
    int res = 1;

    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        a = (a*a) % MOD;
        b >>=1;
    }
    return res;
}




int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        SegTree st1, st2, st3;

        map<int,int> coord;

        memset(dp, 0, sizeof(dp));

        vector<int> a(n+1);

        map<int,int> l, r;

        vector<int> tmp;

        int mx = 0;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            r[a[i]] = -1;
            mx = max(mx, a[i]);
            tmp.push_back(a[i]);
        }

        sort( tmp.begin(), tmp.end() );
        tmp.erase( unique( tmp.begin(), tmp.end() ), tmp.end() );

        for(int i = 0; i < tmp.size(); i++) coord[tmp[i]] = i+1;
        int i = n;
        

        while(1){
            for(int j = i-1; j >= 1; j--){
                if(a[j] > a[i]){
                    r[a[j]] = a[i];
                    i = j;
                    break;
                }
            }

            if(a[i] == mx) break;
        }

        for(int i = 1; i <= n; i++) cout << r[i] << " ";
        cout << "\n";

        i = 1;

        while(1){
            for(int j = i+1; j <= n; j++){
                if(a[j] > a[i]){
                    l[a[j]] = a[i];
                    i = j;
                    break;
                }
            }

            if(a[i] == mx) break;
        }
        dp[n][1] = 1;
        st2.add(1,1,n, coord[a[n]], coord[a[n]], dp[n][1]);
        st3.add(1,1,n, coord[a[n]], coord[a[n]], dp[n][1]);   
        if(a[n] == mx) st1.add(1,1,n, coord[l[a[n]]], coord[l[a[n]]], dp[n][1]);



        for(int i = n-1; i >= 1; i--){

            //cout << "r " << i << " " << l[a[i]] << " " << r[a[i]] << " " << a[i] << " " << coord[a[i]] << "\n";

            //for(int i = 1; i <= n; i++) cout << st2.query(1,1,n, i,i) << " ";
            //cout << "\n";

            //for(int i = 1; i <= n; i++) cout << st3.query(1,1,n, i,i) << " ";
            //cout << "\n";

            st1.mult(1,1,n, coord[a[i+1]], n, 2);
            dp[i][0] = st1.query(1,1,n, coord[a[i]],coord[a[i]]);
            st1.add(1,1,n, coord[l[a[i]]], coord[l[a[i]]], dp[i][0]);


            
            dp[i][1] = st2.query(1,1,n, coord[r[a[i]]], coord[r[a[i]]]);
            //cout << i << " " << st3.query(1,1,n, coord[a[i]], coord[a[i]]) << "\n";
            dp[i][1] = (dp[i][1] + st3.query(1,1,n, coord[a[i]], coord[a[i]])) % MOD;

            //multiply all values that have r[i] > me
            st2.mult(1,1,n, coord[a[i]]+1, n, 2);
            st3.mult(1,1,n, coord[a[i]]+1, n, 2);
            if(a[i] == a[n]) dp[i][1]++;
            st2.add(1,1,n, coord[a[i]], coord[a[i]], dp[i][1]);
            st3.add(1,1,n, coord[a[i]], coord[a[i]], dp[i][1]);

            //cout << dp[i][1] << "\n";


            if(a[i] == mx) st1.add(1,1,n, coord[l[a[i]]], coord[l[a[i]]], dp[i][1]);
            
        }

        //for(int i = 1; i <= n; i++) cout << dp[i][0] << " ";
        //cout << "\n";
        //for(int i = 1; i <= n; i++) cout << dp[i][1] << " ";
        //cout << "\n";
       
    
        int sm = 0;

        for(int i = 1; i <= n; i++) sm = (sm + dp[i][mx == a[1]] * (a[i] == a[1]))%MOD;

        cout << max(sm, 1LL) << "\n";


        
    }
}