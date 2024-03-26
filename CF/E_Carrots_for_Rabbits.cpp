#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, k, a[MAXN];
bool can(int x){
    int cnt = 0;

    for(int i = 1; i <= n; i++) cnt += a[i]/x;
    return cnt <= k;
}