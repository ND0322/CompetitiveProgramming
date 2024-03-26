#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n,k,q,a[MAXN],st[MAXN<<1], ans[MAXN<<1];


//index of max
//ans is a max segtree to keep track of the answer at each ind

void build(){
    for(int i = n-1; i > 0; i--){
        //cout << i << " " << st[i<<1] << " " << st[i<<1|1] << "\n";
        if(a[st[i<<1]] > a[st[i<<1|1]]) st[i] = st[i<<1];
        else st[i] = st[i<<1|1];
    }
       
    
}

void update(int i){
    for(i += n; i > 1; i >>= 1){
        if(a[st[i]] > a[st[i^1]]) st[i>>1] = st[i];
        else st[i>>1] = st[i^1];
    }
}

void updateAns(int i, int val){
    for(ans[i+=n] = val; i > 1; i>>=1) ans[i>>1] = max(ans[i],ans[i^1]);
}

int query(int l, int r){
    if(r < l) return n;
    int res = n;
    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1){
            if(a[st[l]] > a[res]) res = st[l];
            l++;
        }
        if(r&1){
            if(a[st[r-1]] > a[res]) res = st[r-1];
            r--;
        }
    }

    return res;
}



int queryAns(int l, int r){
    int res = 0;
    for(l += n, r += n; l < r; l>>=1, r>>=1){
        if(l&1) res = max(res, ans[l++]);
        if(r&1) res = max(res, ans[--r]);
    }
    return res;
}

void upd(int i){
    int l = query(max(0,i-k+1),i);
    int r = query(i+1,min(n,i+k));

        //if(i == 0) cout << l << " " << r << "\n";

        
    if(a[i] < a[l] || a[i] < a[r]) return;
    updateAns(i,a[i] + max(a[l],a[r]));
}




//k = 3
// 8 4 2 1 3 5 6 7 4 2 5





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int last;
    cin >> n >> k >> q;

    
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) st[i+n] = i;
    

    build();

    

    //a[0] = 0;
    //update(0);

   

   

    //cout << query(0,n) << "\n";
    //cout << a[query(0,n)] << "\n";


    for(int i = 0; i < n; i++){
        upd(i);

    }

    cout << (last = queryAns(0,n)) << "\n";

    

    while(q--){
        int i, x; cin >> i >> x;

        i^= last;
        x^= last;

        i--;

        a[i] = x;
        update(i);

        

        int l = query(max(0,i-k+1),i);
        int r = query(i+1,min(n,i+k));

        //cout << l << " " << r << "\n";

        if(a[i] < a[l] || a[i] < a[r]){
            //the val stored in ans i is invalid
            updateAns(i,-1);

            //recalculate

            if(l != n) upd(l);

            if(r != n) upd(r);
        }
        else updateAns(i,a[i] + max(a[l],a[r]));

        cout << (last = queryAns(0,n)) << "\n";
    }
    



   
}