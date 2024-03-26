#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3005;

#define int long long

int n, h , dp[MAXN];

pair<int,int> a[MAXN];



//for each tree we can go right some and come back
//cost will be like 2 * (p[j] - p[i])

//im sped its the max of the interval obviously

//take the max of the two


//calc extra time with dp and add to h

int32_t main(){
    cin >> n >> h;

    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a,a+n);

    for(int i = n-1; i >= 0; i--){
        dp[i] = 1e9;
        int mx = a[i].second;
        for(int j = i; j < n; j++){
            mx = max(mx, a[j].second);
            dp[i] = min(dp[i], max(2*(a[j].first - a[i].first), mx) + dp[j+1]);
        }
    }

    cout << dp[0] + h << "\n";

    
}

//ac
//22 minutes yikes