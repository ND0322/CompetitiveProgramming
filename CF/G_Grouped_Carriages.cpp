#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], d[MAXN];

vector<pair<int,int>> l[MAXN];

//segments with left endpoint at i

bool can(int x){
    priority_queue<pair<int,long long>, vector<pair<int,long long>>, greater<pair<int,long long>>> pq;

    for(int i = 1; i <= n; i++){
        if(pq.size() && pq.top().first < i) return 0;

        for(pair<int,long long> j : l[i]) pq.push(j);

        long long cnt = 0;

        while(!pq.empty() && cnt < x){
            int r = pq.top().first;
            long long y = pq.top().second;
            pq.pop();
            long long tmp = min(y,x-cnt);


            cnt += tmp;
            if(tmp < y) pq.push({r, y-tmp});
        }
    }

    return pq.empty();


}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> d[i];

    for(int i = 1; i <= n; i++) l[max(1,i-d[i])].push_back({min(n, i+d[i]),a[i]});

    bool flag = 1;
    for(int i = 1; i <= n; i++) flag &= !a[i];

    if(flag){
        cout << "0\n";
        return 0;
    }

    int lo = 0;
    int hi = 1e9;
    int ans = -1;


    //cout << can(5) << "\n";

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;
    }

    cout << ans << "\n";



}