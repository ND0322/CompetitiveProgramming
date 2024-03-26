#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1e6+5;
const int MOD = 1e6+3;

int n, a[MAXN], b[MAXN];





/*
the question can be handled in three parts:
from 1 to l of peak
from l to r of peak
from r of peak to n

parts 1 and 3 we simply lift each one up to the pmax and smax respectively
part 2 we lift to the peak height

we can split each mountain into searching prefix and suffix
for each mountain do the query and then add the range into the prefix

*/



int main(){
    cin >> n;

    pair<int,int> peak = {-1,-1};

    int pmax = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        peak = max(peak, {a[i], i});
        pq.push({a[i],i});

        pmax = max(pmax, a[i]);

        b[i] = pmax;
    }

    int smax = 0;

    for(int i = n; i >= peak.second; i--){
        smax = max(smax, a[i]);
        b[i] = smax;
    }

    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << "\n";


    long long ans = 0;

    //could sort by a[i] breaking ties by b[i]

    while(pq.size()){
        auto [x,id] = pq.top();

        pq.pop();

        if(x == b[id]) continue;

        int res = 1e9;

        for(int i = 1; i < id; i++){
            if(a[i] > x) res = min(res, a[i]);
        }

        cout << x << " " << id << " " << res << " ";

        ans = (ans+res) % MOD;
        ans = (ans+x) % MOD;

        res = 1e9;

        for(int i = id+1; i <= n; i++){
            if(a[i] > x) res = min(res, a[i]);
        }
        cout << res << "\n";
        ans = (ans+res) % MOD;

        a[id]++;

        if(a[id] == b[id]) continue;
        pq.push({a[id],id});
    }

    cout << ans << "\n";
   





}