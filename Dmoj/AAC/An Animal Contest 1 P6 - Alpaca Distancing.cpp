#include <bits/stdc++.h>
#include <iostream>
#include <set>


using namespace std;

const int MAXN = 1e5+5;

int n, dp[MAXN];

pair<int,int> a[MAXN];

set<pair<int,int>> pos;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) pos.insert({a[i].first, i});

    for(int i = n; i >= 1; i--){
        
    }
}

