#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


//if we have some far right s, f(s) is 0
//if we have any s on the way such that f(s) > k then we know that at some point f(s) == k in that interval
//we can binary search for s on this interval

int n;

vector<int> psa;
vector<pair<int,int>> ranges;


int query(int x){
    if(x < ranges[1].first) return 0;

    //largest l <= i
    int lo = 1;
    int hi = n;

    int ind = 0;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(ranges[mid].first <= x){
            lo = mid+1;
            ind = mid;
        }
        else hi = mid-1;
    }

    int ans = psa[ind-1];

    ans += max(0LL, min(x, ranges[ind].second) - ranges[ind].first + 1);
    return ans;
}


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int m, k; cin >> n >> m >> k;

        psa = vector<int>(n+5);
        ranges = vector<pair<int,int>> (n+5);
        
        map<int,int> li;
        
        for(int i = 1; i <= n; i++){
            cin >> ranges[i].first >> ranges[i].second;
            psa[i] = psa[i-1] + ranges[i].second - ranges[i].first + 1;
        }

        if(k == 0){
            cout << (int)1e16 << "\n";
            continue;
        }

        int lo = -1;
        int hi = -1;
        for(int i = n; i >= 1; i--){
            //find first r greater than ri + m - 1



            if(query(ranges[i].first + m - 1) - query(ranges[i].first - 1) >= k){
                lo = ranges[i].first;
                hi = ranges[i].second;
                break;
            }
        }

        //cout << lo << "\n";

        if(lo == -1){
            cout << "-1\n";
            continue;
        }


        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            //cout << mid << " " << val << "\n";
            if(query(mid+m-1) - query(mid-1) >= k){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        cout << ans << "\n";
            
        
    }
    
}