#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

const int MAXN = 1e6+5;

int main(){
    int n; cin >> n;

    multiset<long long> pq;
    //had a pq here but no

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        pq.insert(x);
    }

    long long ans = 0;

    while(pq.size() > 1){
        long long a = *pq.begin();

        pq.erase(pq.begin());

        //pq.pop();

        //long long b = pq.top();

        long long b = *pq.rbegin();

        pq.erase(pq.find(b));

        ans += min(a,b);
        pq.insert(a+b);
    }

    cout << ans << "\n";
}