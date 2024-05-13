#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, k, psa[MAXN];

pair<int,int> a[MAXN];



int32_t main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

    sort(a+1,a+n+1);

    for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + a[i].second;

    int ans = 0;
    //could use 2p but whatever
    for(int i = 1; i <= n; i++){
        int lo = i+1;
        int hi = n;
        int nxt = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(a[mid].first - a[i].first < k){
                lo = mid+1;
                nxt = mid;
            }
            else hi = mid-1;
        }

        if(nxt == -1) ans = max(ans, a[i].second);
        ans = max(ans, psa[nxt] - psa[i-1]);
    }

    cout << ans << "\n";
}
