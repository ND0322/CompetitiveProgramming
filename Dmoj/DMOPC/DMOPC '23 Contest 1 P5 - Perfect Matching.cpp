#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,q, a[MAXN], b[MAXN];

int main(){
    cin >> n >> q;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a,a+n);
    sort(b,b+n);

    long long ans = 0;

    for(int i = 0; i < n; i ++) ans += abs(a[i]-b[i]);

    cout << ans << "\n";
}