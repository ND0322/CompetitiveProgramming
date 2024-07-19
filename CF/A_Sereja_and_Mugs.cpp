#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n,k; cin >> n >> k;

    long long sm = 0;
    int mx = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        sm += x;
        mx = max(mx, x);
    }

    cout << (sm - mx <= k ? "YES\n" : "NO\n");
}