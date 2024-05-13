#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;
const int INF = 1e9;


int n, a[MAXN];

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;

    for(int i = 0; i <= 30; i++){
        int best = 0;
        int sm = 0;

        for(int j = 1; j <= n; j++){
            sm += (a[j] > i ? -INF : a[j]);
            best = min(best, sm);

            ans = max(ans, sm - best - i);
        }
    }


    cout << ans << "\n";
}