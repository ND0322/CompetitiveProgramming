#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 605;

int n, a[MAXN], dp[MAXN], b[MAXN];


//if they all the same then no
void solve(){
    cin >> n;

    bool flag = 1;
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
        flag &= (a[i] == a[1]);
    }
    sort(a+1,a+n+1);

    if(n&1){
        for(int i = 1; i < n; i++) cout << a[i] << " ";
        cout << a[n] << "\n";
        return;
    }
    if(flag){
        cout << "-1\n";
        return;
    }
    
    int l = 1;
    int r = n;
    int cnt = 1;

    vector<int> ans;

    while(l < r){
        ans.push_back(a[r--]);
        ans.push_back(a[l++]);
    }

    for(int i = 0; i < n-1; i++) cout << ans[i] << " ";
    cout << ans[n-1] << "\n";
    



}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
    }
}

