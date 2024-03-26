#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main(){

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        ll ans = 0;
        priority_queue<int> pq;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(x == 0){
                if(!pq.empty()){
                    ans+=pq.top();
                    pq.pop();
                }
            }
            pq.push(x);
        }

        cout << ans << "\n";
    }
    
}