#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//find next with monotnic stack
//for second half either transition to equal
//add 2 ^ length
//coord compress
//range multiply by 2


const int MAXN = 3e5+5;
const int MOD = 998244353;

long long dp[MAXN][2];

struct Node{
    long long lzA = 0, lzM = 1,val = 0;

    }st[MAXN<<2][2];

   
void pushdown(int node, int l, int r, bool p){
    int mid = (l+r)>>1;
    
    if(l != r){
        st[node<<1][p].val = (st[node<<1][p].val * st[node][p].lzM % MOD + (mid - l + 1) * st[node][p].lzA % MOD) % MOD;
        st[node<<1|1][p].val = (st[node<<1|1][p].val * st[node][p].lzM % MOD + (r - mid) * st[node][p].lzA % MOD) % MOD;
    }
    st[node<<1][p].lzM = (st[node<<1][p].lzM * st[node][p].lzM) % MOD;
    st[node<<1|1][p].lzM = (st[node<<1|1][p].lzM * st[node][p].lzM) % MOD;
    st[node<<1][p].lzA = ((st[node<<1][p].lzA * st[node][p].lzM)%MOD + st[node][p].lzA) % MOD;
    st[node<<1|1][p].lzA = ((st[node<<1|1][p].lzA * st[node][p].lzM)%MOD + st[node][p].lzA) % MOD;

    
    
    st[node][p].lzA = 0;
    st[node][p].lzM = 1;
}

void add(int node, int l, int r, int x, int y, int v, bool p){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node][p].lzA = (st[node][p].lzA + v) % MOD;
        st[node][p].val = (st[node][p].val + ((r - l + 1) * v) % MOD) % MOD;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node,l,r, p);
    add(node<<1, l, mid, x, y, v, p);
    add(node<<1|1, mid+1,r,x,y,v, p);
    st[node][p].val = (st[node<<1][p].val + st[node<<1|1][p].val) % MOD;
}

void mult(int node, int l, int r, int x, int y, int v, bool p){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node][p].lzM = (st[node][p].lzM * v) % MOD;
        st[node][p].lzA = (st[node][p].lzA * v) % MOD;
        st[node][p].val = (st[node][p].val * v) % MOD;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node,l,r, p);
    mult(node<<1, l, mid ,x,y,v, p);
    mult(node<<1|1, mid+1,r,x,y,v, p);
    st[node][p].val = (st[node<<1][p].val + st[node<<1|1][p].val) % MOD;
}

int query(int node, int l, int r, int x, int y, bool p){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node][p].val;
    int mid = (l+r)>>1;
    pushdown(node, l, r,p);
    return (query(node<<1, l, mid, x, y, p) + query(node<<1|1, mid+1,r,x,y, p)) % MOD;
}





long long binpow(int a, int b){
    long long res = 1;

    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        a = (a*a) % MOD;
        b >>=1;
    }
    return res;
}




int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        map<int,int> coord;

        vector<int> a(n+1);

        map<int,int> l, r;

        vector<int> tmp;

        mult(1,1,n,1,n,0,0);
        mult(1,1,n,1,n,0,1);

        int mx = 0;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i][0] = 0;
            dp[i][1] = 0;
            r[a[i]] = -1;
            mx = max(mx, a[i]);
            tmp.push_back(a[i]);
        }

        sort( tmp.begin(), tmp.end() );
        tmp.erase( unique( tmp.begin(), tmp.end() ), tmp.end() );

        for(int i = 0; i < tmp.size(); i++) coord[tmp[i]] = i+1;
        int i = n;
        int j = n;

        while(1){
            if(a[i] == mx) break;
            while(j >= 1 && a[j] <= a[i]) j--;
            r[a[j]] = a[i];
            i = j;
            
        }

        i = 1;
        j = 1;

        while(1){
            if(a[i] == mx) break;
            while(j <= n && a[j] <= a[i]) j++;
            l[a[j]] = a[i];
            i = j;
        }
        dp[n][1] = 1;
        add(1,1,n, coord[a[n]], coord[a[n]], dp[n][1], 1);   
        if(a[n] == mx) add(1,1,n, coord[l[a[n]]], coord[l[a[n]]], dp[n][1], 0);



        for(int i = n-1; i >= 1; i--){

            //cout << "r " << i << " " << l[a[i]] << " " << r[a[i]] << " " << a[i] << " " << coord[a[i]] << "\n";

            //for(int i = 1; i <= n; i++) cout << st2.query(1,1,n, i,i) << " ";
            //cout << "\n";

            //for(int i = 1; i <= n; i++) cout << st3.query(1,1,n, i,i) << " ";
            //cout << "\n";

            mult(1,1,n, coord[a[i+1]], n, 2, 0);
            dp[i][0] = query(1,1,n, coord[a[i]],coord[a[i]], 0);
            add(1,1,n, coord[l[a[i]]], coord[l[a[i]]], dp[i][0], 0);


            
            dp[i][1] = query(1,1,n, coord[r[a[i]]], coord[r[a[i]]], 1);
            //cout << i << " " << st3.query(1,1,n, coord[a[i]], coord[a[i]]) << "\n";
            dp[i][1] = (dp[i][1] + query(1,1,n, coord[a[i]], coord[a[i]], 1)) % MOD;

            //multiply all values that have r[i] > me
            mult(1,1,n, coord[a[i]]+1, n, 2, 1);
            if(a[i] == a[n]) dp[i][1]++;
            add(1,1,n, coord[a[i]], coord[a[i]], dp[i][1], 1);

            //cout << dp[i][1] << "\n";


            if(a[i] == mx) add(1,1,n, coord[l[a[i]]], coord[l[a[i]]], dp[i][1], 0);
            
        }
       
    
        long long sm = 0;

        for(int i = 1; i <= n; i++) sm = (sm + dp[i][mx == a[1]] * (a[i] == a[1]))%MOD;

        cout << max(sm, 1LL) << "\n";


        
    }
}