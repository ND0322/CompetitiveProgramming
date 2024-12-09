#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

#define int long long


//sweepline offline type shit
//each rightend point we remove i which is prefix from the cur
//add n-i things too
//this hold from x[i] to x[i+1]

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, q; cin >> n >> q;

        vector<int> x(n+5);

        for(int i = 1; i <= n; i++) cin >> x[i];

        long long cur = 0;

        map<int,int> mp;

        for(int i = 1; i <= n; i++){
            cur = n-i + (i-1) * (n-i+1);
            mp[cur] += 1;
            cur -= i-1;
            mp[cur] += x[i+1] - x[i]-1;

        }

        while(q--){
            int y; cin >> y;

            cout << mp[y] << " ";
        }

        cout << "\n";
    }
}