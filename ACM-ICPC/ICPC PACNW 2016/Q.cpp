#include <bits/stdc++.h>
#include <iostream>
#include <queue>

#define int long long

using namespace std;


int n,k,t[305];

int32_t main(){
    cin >> n >> k;

    int cur = 0;
    int ans = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        pq.push(x);
        if(k) k--;
        if(!k){
            cur += pq.top();
            ans += cur;

            pq.pop();
        }


    }

    while(!pq.empty()){
        cur += pq.top();
        ans+=cur;

        pq.pop();
    }

    cout << ans << "\n";
}
