#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e5+5;

int a[MAXN];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
 
        set<int>st{a[n-1]};
        int mx=a[n-1],xr=a[n-1];
    for(int i = n-2; i >= 0; i--){
        xr^=a[i];
        mx=max({mx,a[i],xr});
        for(auto it:st) 
        {
            mx=max(mx,xr^it);
        }
        st.insert(xr);
    }
    cout << mx << "\n";
    }
}
    