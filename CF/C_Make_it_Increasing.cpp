#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], b[MAXN];
int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    long long ans = 0;

    for(int i = 2; i <= n; i++){
        ans += ceil(b[i-1]+1/a[i]);

        b[i] = a[i] * ceil(b[i-1]+1/a[i]);
    }

    cout << ans << "\n";
}

