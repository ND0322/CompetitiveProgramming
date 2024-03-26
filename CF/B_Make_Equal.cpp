#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN];

void solve(){
    int n; cin >> n;

    int tot = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        tot += a[i];
    }

    tot /= n;

    for(int i = 1; i <= n; i++){
        if(a[i] < tot){
            cout << "NO\n";
            return;
        }

        a[i+1] += (a[i] - tot);
    }

    cout << "YES\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();


    }
}