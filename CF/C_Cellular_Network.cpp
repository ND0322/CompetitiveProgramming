#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n,m, a[MAXN], b[MAXN];

set<int> s;

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= m; j++){
        cin >> b[j];
        s.insert(b[j]);
    }

    long long ans = 0;

    for(int i = 1; i <= n; i++){
        long long l = 1e18;
        long long r = 1e18;

        auto it = s.lower_bound(a[i]);

        if(it != s.end()) r = *it - a[i];
        if(it != s.begin()){
            it--;
            l = a[i] - *it;
        }

        ans = max(ans, min(l,r));
    }

    cout << ans << "\n";

}