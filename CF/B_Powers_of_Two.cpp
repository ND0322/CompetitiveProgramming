#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN];

map<int,int> cnt;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    long long ans = 0;

    for(int i = 1; i <= n; i++){
        cnt[a[i]]--;
        for(long long x = 1; x <= 2e9; x<<=1) ans += cnt[x-a[i]];
    }

    cout << ans << "\n";
}

