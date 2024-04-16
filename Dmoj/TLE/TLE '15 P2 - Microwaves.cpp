#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long

const int MAXN = 1e5+5;

int n, m, k, last[MAXN];

pair<int,int> a[MAXN];

priority_queue<int,vector<int>,greater<int>> pq;


int32_t main(){
    cin >> m >> n >> k;

   

    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    

    sort(a+1,a+n+1);

    for(int i = 1; i <= n; i++){
        pair<int,int> opt = {1e18,-1};
        for(int j = 1; j <= m; j++){
            opt = min(opt, {last[j], j});
            if(a[i].first - last[j] >= k){
                cout << last[j] << "\n";
                return 0;
            }
        }
        
        last[opt.second] = max(a[i].first, opt.first) + a[i].second;
    }

    pair<int,int> opt = {1e18,-1};
    for(int j = 1; j <= m; j++) opt = min(opt, {last[j], j});
    cout << opt.first << "\n";
  

        

    

}
