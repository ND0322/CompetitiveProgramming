#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve(){
    int n,k; cin >> n >> k; 

    vector<pair<int,int>> a(n+1);
    vector<int> b(n+1);
    vector<int> ans(n+1);

    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 1; i <= n; i++) cin >> b[i];

    sort(a.begin()+1, a.end());
    sort(b.begin()+1, b.end());

    for(int i = 1; i <= k; i++){
        if(!(a[n-k+i].first > b[i])){
            cout << "NO\n";
            return;
        }

        ans[a[n-k+i].second] = b[i];
    }

    for(int i = 1; i <= n-k; i++){
        if(!(a[i].first <= b[i+k])){
            cout << "NO\n";
            return;
        }

        ans[a[i].second] = b[i+k];
    }

    cout << "YES\n";

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
    }
}