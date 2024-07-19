#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

#define int long long

const int MAXN = 5005;

int n, dp[MAXN][MAXN], sm;

pair<int,int> a[MAXN];
map<int,int> mp;

/*
assume a sorted set of rods

its clear that in sorted order, ai + ai+1 < ai+2

sum the value of all sticks of equal length

dp[i] => index i

transitions

i => i+1

or we take i and loop j and bsearch for next possible

last taken in the state?

last taken in state and current considering same ish transitions but easier
*/

int32_t main(){
    cin >> n;

    a[0] = {0,0};
    

    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
        sm += a[i].second;
    }

    sort(a,a+n+1);

    a[n+1] = {1e18, 1e18};

    for(int i = n; i >= 1; i--){
        for(int j = 0; j < i; j++){
            dp[i][j] = dp[i+1][j];

            //take

            int lo = i+1;
            int hi = n;

            int nxt = 0;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(a[i].first + a[j].first <= a[mid].first){
                    nxt = mid;
                    hi = mid-1;
                }
                else lo = mid+1;
            }

            //cout << j << " " << i << " " << nxt << "\n";

            dp[i][j] = max(dp[i][j], dp[nxt][i] + a[i].second);
        }
    }

    cout << sm - dp[1][0] << "\n";
}