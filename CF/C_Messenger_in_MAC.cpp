#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

//isnt this question easy


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<pair<int,int>> a(n);

        for(int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;

        sort(a.begin(), a.end());

        long long ans = 0;

        for(int i = 0; i < n; i++){
            priority_queue<int> pq;

            long long sum = 0;

            for(int j = i; j < n; j++){
                pq.push(a[j].second);
                sum += a[j].second;

                
                while(pq.size() && sum + a[j].first - a[i].first > k){
                    sum -= pq.top();
                    pq.pop();
                }
               
                //cout << i << " " << j << " " << pq.size() << "\n";
                ans = max(ans, (long long)pq.size());
            }
        }

        cout << ans << "\n";
    }
}