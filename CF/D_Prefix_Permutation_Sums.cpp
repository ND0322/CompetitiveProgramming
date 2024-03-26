#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

typedef long long ll;

int n;

bool has[MAXN];

priority_queue<ll,vector<ll>,greater<ll>> pq;

int can(ll x, priority_queue<ll,vector<ll>,greater<ll>> q){
    q.push(x);

    fill(has,has+n+1,false);

    while(pq.size() > 1){
        ll first = q.top();

        q.pop();

        if(q.top() - first > n){
            return q.top() - first;
        }

        if(has[q.top() - first]){
            return q.top()-first;
        }

        has[q.top()-first];
    }

    return true;
    
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        while(!pq.empty()) pq.pop();

        for(int i = 0; i < n-1; i++){
            ll x; cin >> x;
            pq.push(x);
        }

        ll lo = 0;
        ll hi = 1e18;

        while(lo <= hi){
            ll mid = (lo + hi)/2;

            if
        }



        
    }
}