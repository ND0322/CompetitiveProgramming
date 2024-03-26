#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN];

long long m;

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];

    int r = -1;
    long long sum = 0;
    int ans = 0;

    for(int i = 0; i < n; i++){
        while(r < n-1 && sum + a[r+1] < m) sum += a[++r];
        ans = max(ans, r-i+1);
        sum -= a[i];
    }

    cout << ans << "\n";
}