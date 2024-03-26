#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        long long ans = 0;
        int last = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            x %= k;


            //non increasing
            if(last >= x) pq.push(x+k-last);
            else{
                pq.push(x-last);
                ans += pq.top();
                pq.pop();
            }

            last = x;
        }

        cout <<ans << "\n";


    }
}