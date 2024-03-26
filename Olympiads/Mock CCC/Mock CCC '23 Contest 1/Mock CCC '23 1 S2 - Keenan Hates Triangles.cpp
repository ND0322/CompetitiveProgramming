#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 998244353;

int main(){
    int n; cin >> n;
    
    long long ans = 1;

    for(int i = 1; i <= n; i++) ans = (ans * i) % MOD;
    cout << ans << "\n";


}


/*
try to solve a quickly
b go with your instinct instead of just sitting there
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/