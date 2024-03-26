#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long


typedef pair<int,int> pii;
typedef pair<pii,pii> edge;
typedef long double ld;

const int MAXN = 3e5+5;

int n, q;

pii a[MAXN];

deque<pii> cht;

ld intersect(pii l, pii ll){
    return (ll.second - l.second)/(ld)(l.first - ll.first);
}


void insert(pii x){
    while(cht.size() >= 2 && intersect(cht[cht.size() - 2], cht.back()) <= intersect(cht[cht.size() - 2], x)) cht.pop_back();
    cht.push_back(x); 
}


int32_t main() {
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    
    
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    cin >> q;

    long long last = 0;
    
    for (int i = 1; i <= n; i++){
        if (a[i].second <= last) continue;
        last = a[i].second;
        //cout << last << "\n";
        insert(a[i]);
    }

    //cout << cht.size() << "\n";

    while(q--){
        int x,y; cin >> x >>y;

        ld r = x/(ld)y;

        int lo = 0;
        int hi = cht.size()-2;

        int ans = cht.size()-1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(intersect(cht[mid], cht[mid+1]) < r){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        //cout << ans << "\n";
        cout << x * cht[ans].first + y * cht[ans].second << "\n";


    }

    
}