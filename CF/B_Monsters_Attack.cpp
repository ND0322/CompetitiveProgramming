#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

#define int long long 


const int MAXN = 3e5+5;

int n, k;

pair<int,int> a[MAXN];

//i was being dumb

void solve(){

 
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i].second;
    for(int i = 1; i <= n; i++) cin >> a[i].first;

    for(int i = 1; i <= n; i++) a[i].first = abs(a[i].first);

    sort(a+1,a+n+1);

    int saved = 0;
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        cnt += a[i].second;

        if((cnt-1)/k+1 > a[i].first){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

}


int32_t main(){
    int tt; cin >> tt;

    while(tt--) solve();
    
    
}