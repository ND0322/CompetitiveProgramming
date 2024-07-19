#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1e5+5;

#define int long long

//for each thing we have to search for if it can be the middle
//psum and ssum of each and if we can mix and match to work

//we need k+1 bigger and k smaller 

int n, a[MAXN], psa[MAXN], bac[MAXN];

map<int,int> mp;

bool can(int x){
    for(int i = 1; i <= n; i++){
        if(a[i] >= x) psa[i] = psa[i-1] + 1;
        else psa[i] = psa[i-1] - 1;
    }

    int mx = psa[2];

    int mn = 0;

    for(int i = 3; i <= n; i++){
        mn = min(mn, psa[i-2]);
        mx = max(mx, psa[i] - mn);
    }

    return mx > 0;
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        set<int> s;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }

        int cnt = 0;
        for(int i : s){
            cnt++;
            mp[i] = cnt;
            bac[cnt] = i;
        }
        
        for(int i = 1; i <= n; i++) a[i] = mp[a[i]];

        int lo = 1;
        int hi = n+1;

        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(can(mid)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        cout << bac[ans] << "\n";
    }
}