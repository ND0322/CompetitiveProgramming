#include <bits/stdc++.h>
#include <iostream>

using namespace  std;

#define int long long

/*
after operation a[i] parity remains the same 
in other words order of operations doesnt really matter for what moves are avaiable, just how good they are
swapping differences 

we have some fixed points so we build from there 
*/



int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        vector<int> a(n+1);
        vector<int> d(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i < n; i++) d[i] = a[i+1] - a[i];

        vector<int> ans(n+1);
        priority_queue<int, vector<int>, greater<int>> pq;

        int p = 2;
        ans[1] = a[1];
        for(int i = 1; i < n; i++){
            pq.push(d[i]);
            if(i == n-1 || (d[i] & 1) != (d[i+1] & 1)){
                while(pq.size()){
                    ans[p] = ans[p-1] + pq.top();
                    p++;
                    pq.pop();
                }
            }
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}