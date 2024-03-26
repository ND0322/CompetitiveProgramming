#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

const int MAXN = 1e5+5;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

int n,templ[MAXN], tempr[MAXN], l[MAXN], r[MAXN], dp[MAXN], sl[MAXN<<1], sr[MAXN<<1], st[MAXN<<1];

pair<long long,long long> a[MAXN];

ost t;


void update(int i, int val){
    for(st[i+=n] = val; i > 1; i>>=1) st[i>>1] = min(st[i],st[i^1]);
}


void updater(int i, int val){
    for(sr[i+=n] = val; i > 1; i >>=1) sr[i>>1] = max(sr[i],sr[i^1]);
}

void updatel(int i, int val){
    for(sl[i+=n] = val; i > 1; i >>=1) sl[i>>1] = min(sl[i],sl[i^1]);
}

int queryl(int l, int r){
    int ans = 1e9;

    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) ans = min(ans,sl[l++]);
        if(r&1) ans = min(ans,sl[--r]);
    }

    return ans;
}


int queryr(int l, int r){
    int ans = 0;

    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) ans = max(ans,sr[l++]);
        if(r&1) ans = max(ans,sr[--r]);
    }

    return ans;
}

int query(int l, int r){
    int ans = 1e9;

    for(l += n, r+= n; l < r; l>>=1, r>>=1){
        if(l&1) ans = min(ans,st[l++]);
        if(r&1) ans = min(ans,st[--r]);
    }

    return ans;
}



//precompute left most and right most for each domino
//dp options: 1. push down current domino to the right and go to the precomputed right
//dp options: 2. have this dominoe get pushed by something to the right of it that would reach it. This is monotonic and use segtree to optimize


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;



    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;

        t.insert(a[i].first);
        
        updatel(i,n+1);
    }
    
    

    sort(a,a+n);

    //use segtree for all
    
    
    
    //for(int i = 0; i < n; i++) cout << t.order_of_key(a[i].first + a[i].second+1)-1 << "\n";



    for(int i = n-1; i >= 0; i--){
        tempr[i] = i;
        
        //cout << i << " " << t.order_of_key(a[i].first + a[i].second+1) << " " << queryr(i,t.order_of_key(a[i].first + a[i].second+1)) << "\n";
        

        tempr[i] = max(tempr[i], queryr(i, t.order_of_key(a[i].first + a[i].second+1)));
        updater(i, tempr[i]);
        
        //cout << r[i] << "\n";
        
        //for(int j = i+1; j < n; j++){
            //if(a[j].first > a[i].first + a[i].second) break;

            //r[i] = max(r[i], r[j]);

        //}
    }
    
    
    /*
    for(int i = 0; i < n; i++){
    	cout << i << " " << i-(t.order_of_key(a[i].first) - t.order_of_key(a[i].first-a[i].second)) << "\n";
    	cout << queryl(i-(t.order_of_key(a[i].first) - t.order_of_key(a[i].first-a[i].second)),i+1) << "\n";
    	updatel(i,l[i]);
    }	
    */
    
    
    
    for(int i = 0; i < n; i++){
    	templ[i] = i;
    	
    	templ[i] = min(templ[i], queryl(i-(t.order_of_key(a[i].first) - t.order_of_key(a[i].first-a[i].second)),i));
    	updatel(i,templ[i]);
    }
    

    for(int i = 1; i <= n; i++){
        l[i] = templ[i-1] + 1;
        r[i] = tempr[i-1] + 1;
    }
    
    

    
    
    
    
    fill(dp,dp+n+1, 1e9);
    for(int i = 0; i <= n; i++) update(i,1e9);
    dp[0] = 0;
    
    

    for(int i = 0; i <= n; i++){
        dp[i] = min(dp[i],query(l[i], i+1));
        
        //cout << query(i, l[i]+1) << "\n";

        if(i != n){
            //need to do push and pull together to query a consecutive range
            dp[r[i+1]] = min(dp[r[i+1]], dp[i]+1);
            update(i+1,dp[i]+1);
        }
    }
    

    //for(int i = 0; i < n; i++) cout << l[i] << " " << r[i] << "\n";

    
    cout << dp[n] << "\n";

}