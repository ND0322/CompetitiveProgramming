#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, x; cin >> n >> x;

    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        pq.push(x);
    }

    //not optimal but should pass
    long long sm = 0;
    while(x--){
        long long k = pq.top();

        if(k < 0) break;

        sm += k;

        pq.pop();

        pq.push(k-1);
    }

    cout << sm << "\n";

}