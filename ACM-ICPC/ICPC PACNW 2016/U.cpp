#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int n; cin >> n;

    int big = 0;
    int sum = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        big = max(big,x);
        sum+=x;
    }

    cout << (sum - max((long long) 0, 2*big - sum))/2 << "\n";
}