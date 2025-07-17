#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        cout << min(abs(m - a[1]), abs(m - a[n])) + a[n] - a[1] << "\n";
    }
}