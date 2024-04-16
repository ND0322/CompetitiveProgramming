#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n;

//regrettable greedy

int32_t main(){
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    long long sum = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        sum += x;
        pq.push(x);

        while(sum < 0 && pq.size()){
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << (int)pq.size() << "\n";
}

