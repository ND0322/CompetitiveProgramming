#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, f, k; cin >> n >> f >> k;

        vector<int>a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        int c = a[f-1];

        sort(a.rbegin(), a.rend());

        int lo = n;
        int hi = -1;
        for(int i = n-1; i >= 0; i--){
            if(c == a[i]){
                lo = min(lo, i);
                hi = max(hi, i);
            }
        }

        lo++;
        hi++;

        if(lo > k){
            cout << "NO\n";
            continue;
        }

        if(hi <= k){
            cout << "YES\n";
            continue;
        }

        cout << "MAYBE\n";
    }
}