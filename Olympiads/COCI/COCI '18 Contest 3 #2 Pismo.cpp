#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 1e9;
    for(int i = 1; i < n; i++) ans = min(ans,abs(a[i] - a[i+1]));
    cout << ans << "\n";
}

