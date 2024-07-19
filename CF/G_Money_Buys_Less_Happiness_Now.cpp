#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

int n, k, a[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        for(int i = 1; i <= n; i++) cin >> a[i];

        long long sm = 0;


        priority_queue<int> pq;
        for(int i = 1; i <= n; i++){
            pq.push(a[i]);
            sm += a[i];

            while(pq.size() && sm > (i-1)*k){
                sm -= pq.top();
                pq.pop();
            }
        }

        cout << (int)pq.size() << "\n";
    }
}