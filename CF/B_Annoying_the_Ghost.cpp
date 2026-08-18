#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
when a and b are sorted
a[i] <= b[i] for all i

minimize number of inversions 
*/

void solve(){
    int n; cin >> n;

    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<bool> vis(n+1);

    for(int i = 1; i <= n ;i ++) cin >> a[i];

    for(int i = 1; i <= n; i++) cin >> b[i];


    for(int i = 1; i <= n; i++){   
        bool flag = 0;

        for(int j = 1; j <= n; j++){
            if(vis[j] || a[j] > b[i]) continue;
            a[j] = b[i];
            vis[j] = 1;
            flag = 1;
            break;
        }

        if(!flag){
            cout << "-1\n";
            return;
        }
    }

    long long ans = 0;

    for(int i =1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[j] > a[i]) ans++;
        }
    }

    cout << ans << "\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--) solve();
        
    
}