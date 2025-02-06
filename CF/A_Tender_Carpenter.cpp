#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        bool check = 0;

        for(int i = 1; i < n; i++) check |= (min(a[i], a[i+1])*2 > max(a[i], a[i+1]));

        cout << (check ? "YES\n" : "NO\n");
    }
}