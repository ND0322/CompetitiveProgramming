#include <bits/stdc++.h>
#include <iostream>
#include <queue>

#define int long long

using namespace std;

const int MAXN = 2e5+5;

int n, k, ans[MAXN];

pair<int,int> a[MAXN];

//regrettable greedy

int32_t main(){
    int tt; cin >> tt;
    while(tt--){
        cin >> n >> k;

        for(int i = 1; i <= n; i++) cin >> a[i].second;
        for(int i = 1; i <= n; i++) cin >> a[i].first;

        sort(a+1, a+n+1);
        reverse(a+1,a+n+1);

        priority_queue<int> pq;

        //cheapest k things in that prefix

        long long sm = 0;
        for(int i = 1; i <= n; i++){
            pq.push(a[i].second);
            sm += a[i].second;

            while(pq.size() > k){
                sm -= pq.top();
                pq.pop();
            }
            ans[i+1] = sm;
        }

        long long best = 0;
        long long pre = 0;

        for(int i = n; i > k; i--){
            pre += max(0LL, a[i].first - a[i].second);
            best = max(best, pre - ans[i]);
        }

        cout << best << "\n";
    }  
    
}