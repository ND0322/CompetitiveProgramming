#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        int cnt = 0;

        for(int i = 0; i < n-1; i++) cnt += (a[i+1] - a[i]) / 120;
        cnt += a[0]/120;
        cnt += (1440 - a[n-1]) / 120;
        cout << (cnt >= 2 ? "YES\n" : "NO\n");
    }
}