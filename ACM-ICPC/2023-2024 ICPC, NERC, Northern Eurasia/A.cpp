#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int MAXN = 1e5+5;

int n;

long long x;


queue<pair<long long,long long>> parts[MAXN];
priority_queue<pair<pair<long long,long long>,int>> pq;


int main(){
    cin >> x >> n;

    for(int i = 0; i < n; i++){
        int m; cin >> m;

        long long pref = 0;
        long long prefmin = 1e8;

        while(m--){
            int y; cin >> y;

            pref+=y;
            prefmin = min(pref, prefmin);

            if(pref > 0){
                parts[i].push({prefmin,pref});
                pref = 0;
                prefmin = 1e18;
            }
        }

        //parts[i].push({prefmin,pref});

        if(parts[i].size()) pq.push({{parts[i].front().first,parts[i].front().second}, i});
        //parts[i].pop();
    }

    
    long long ans = x;

    while(pq.size() && x >= -pq.top().first.first){
        x+=pq.top().first.second;
        ans = max(ans, x);
        int tmp = pq.top().second;
        pq.pop();
        parts[tmp].pop();
        if(parts[tmp].size()) pq.push({{parts[tmp].front().first, parts[tmp].front().second}, tmp});
        
    }

    cout << ans << "\n";
    
    
    

    

    
}


