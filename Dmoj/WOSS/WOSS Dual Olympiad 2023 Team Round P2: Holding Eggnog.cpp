#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//ripped off that one leetcode problem

const int MAXN = 1e5+5;

int n, a[MAXN], pmax, smax;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0;
    int r = n;

    long long ans = 0;

    while(l < r){
        pmax = max(pmax, a[l]);
        smax = max(smax, a[r]);

        ans += (pmax < smax ? pmax - a[l++] : smax - a[r--]);
    }

    cout << ans << "\n";


}