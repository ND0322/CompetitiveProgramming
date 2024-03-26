#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, a[MAXN], b[MAXN];



int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        

        priority_queue<int,vector<int>,greater<int>> pq;

        pair<int,int> ans = {-1,-1};
        for(int i = n; i >= 1; i--){
            pq.push(a[b[i]]);
            while(pq.size() > i) pq.pop();

            ans = max(ans, {pq.size() * pq.top(), -i});
        }

        cout << ans.first << " " << -ans.second << "\n";
    }
}