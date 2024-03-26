#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;


long long a[MAXN], k;

int main(){
    cin >> n >> k;


    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);

    long long ans = k+1;
    long long last = a[0];

    for(int i = 1 ; i < n; i++) ans += min(k+1, a[i] - a[i-1]);
    

    cout << ans << "\n";

}