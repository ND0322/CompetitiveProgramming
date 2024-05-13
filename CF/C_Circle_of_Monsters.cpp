#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

//start at the one who has least benefit from last

const int MAXN = 3e5+5;

#define int long long

int n;

pair<int,int> a[MAXN<<1];

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n;



        pair<int,int> start = {1e18, -1};
        for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        

        for(int i = 1; i <= n; i++) a[i+n] = a[i];
        for(int i = 1; i <= n; i++) start = min(start, {a[i].first - max(0LL, a[i].first - a[i+n-1].second), i});
        


        long long ans = 0;
        for(int i = start.second; i < start.second+n; i++){
            ans += max(a[i].first, 0LL);
            a[i+1].first -= a[i].second;
        }

        cout << ans << "\n";



    }
}