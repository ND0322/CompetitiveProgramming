#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], b[MAXN], st[MAXN<<1], st2[MAXN<<1], last[MAXN];

bool good[MAXN];

//need like 3 seg tree for this shi

void build(){
    for(int i = n-1; i > 1; i--){
        st[i] = max(st[i<<1], st[i<<1|1]);
        st2[i] = min(st2[i<<1], st2[i<<1|1]);
    }
}

int query1(int l, int r){
    int ans = 0;

    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) ans = max(ans, st[l++]);
        if(r&1) ans = max(ans, st[--r]);
    }

    return ans;
}


int query2(int l, int r){
    int ans = 1e9;

    for(l+=n, r+=n; l < r; l >>=1, r>>=1){
        if(l&1) ans = min(ans, st2[l++]);
        if(r&1) ans = min(ans, st2[--r]);
    }

    return ans;
}
void solve(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= n; j++) cin >> b[j];

    for(int i = 1; i <= n; i++){
        st[i+n] = a[i];
        st2[i+n] = b[i];
        good[i] = 0;
        last[i] = 0;
    }

    build();

    for(int i = 1; i <= n; i++){
        if(a[i] > b[i]){
            cout << "NO\n";
            return;
        }
    }

    for(int i = 1; i <= n; i++){
        last[a[i]] = i;

        if(a[i] != b[i]){
            if(last[b[i]] == 0) continue;

            if(i == last[b[i]]+1) good[i] |= 1;

            
            
            if(query1(last[b[i]]+1, i) <= b[i] && query2(last[b[i]]+1, i) >= b[i]) good[i] = 1;
        } 
        else good[i] = 1;
    }

    reverse(a+1, a+n+1);
    reverse(b+1,b+n+1);

    for(int i = 1; i <= n; i++){
        st[i+n] = a[i];
        st2[i+n] = b[i];
        last[i] = 0;
    }

    build();

    for(int i = 1; i <= n; i++){
        last[a[i]] = i;

        if(a[i] != b[i]){
            if(last[b[i]] == 0) continue;

            if(i == last[b[i]]+1) good[n-i+1] |= 1;

            //cout << last[b[i]] << " " << i << "\n";

            //cout << query2(last[b[i]], i) << "\n";
            
            
            if(query1(last[b[i]]+1, i) <= b[i] && query2(last[b[i]]+1, i) >= b[i]) good[n-i+1] |= 1;
            
        } 
        
    }

    for(int i = 1; i <= n; i++){
        if(!good[i]){
            //cout << i << "\n";
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";


}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
    }
}