#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int x = a[0];

        for(int i = 1; i < n; i++) x = (x + a[i])/2;

        cout << x << "\n";
    }
}