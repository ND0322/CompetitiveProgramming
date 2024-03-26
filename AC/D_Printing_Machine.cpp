#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pii;

const int MAXN = 2e5+5;

int n;

vector<pii> items;

int main(){
    cin >> n;

    priority_queue<ll,vector<ll>,greater<ll>> pq;

    for(int i = 0; i < n; i++){
        ll t,d; cin >> t >> d;

        items.push_back({t,t+d});
    }

    sort(items.begin(), items.end());

    int i = 0;
    int ans = 0;

    for(ll t = 0;;t++){
       
        if(pq.empty()){
            //done
            if(i == n) break;
            t = items[i].first;
        }

        while(i < n && items[i].first <= t) pq.push(items[i++].second);
        while(pq.size() && pq.top() < t) pq.pop();
        if(pq.size() && t <= pq.top()){
            ans++;
            pq.pop();
        }


    }

    cout << ans << "\n";
}