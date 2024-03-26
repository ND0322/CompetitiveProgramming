#include <bits/stdc++.h>
#include <iostream>

#define int long long

using namespace std;

const int MAXN = 1e6+5;

int n, l, a[MAXN];

int32_t main(){
    cin >> n >> l;


    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int mx = 0;
    int sum = 0;
    int cnt = 0;
    int mn = 1e9;
    for(int i = 1; i <= n; i++){
        sum += a[i];

        if(sum > l) break;

        cnt = i;
        mx = max(mx,a[i]);
    }

    for(int i = cnt+1; i <= n; i++) mn = min(mn, a[i]);


    int ans = cnt;

    //cout << cnt << "\n";

    if(l - sum < 0) sum -= a[cnt+1];

    if(mn <= l-sum) ans++;

    sum -= mx;

    for(int i = cnt+1; i <= n; i++){
        sum += a[i];

        if(sum > l) break;
        cnt = i;
    }

    ans = min(max(ans, cnt-1),n);

    cout << ans << "\n";


    
}