#include <bits/stdc++.h>
#include <iostream>
#include <set>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;

const int MAXN = 105;



int n, a[MAXN];

bool can(int x){
    multiset<int> balls;
    for(int i = 1; i <= n; i++) balls.insert(a[i]);

    for(int i = 1; i <= x; i++){

        if(balls.find(x-i+1) != balls.end()) balls.erase(balls.find(x-i+1));
        else{
            auto it = balls.lower_bound(x-i+1);
            if(it == balls.begin()) return 0;

            it--;
            balls.erase(it);
        }
        
        if(balls.empty()) continue;
        balls.erase(balls.begin());
    }

    return 1;

}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        int lo = 0;
        int hi = n;
        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(can(mid)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        cout << ans << "\n";

    }
}