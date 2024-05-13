#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], k;

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];


    int r = 1;
    long long sm = 0;
    int ans = 0;

    for(int i = 1; i <= n; i++){
        while(r <= n && sm+a[r] <= k) sm += a[r++];
        ans = max(ans, r-i);
        sm -= a[i];
    }

    cout << ans << "\n";
}