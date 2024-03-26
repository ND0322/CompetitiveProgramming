#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        //take the free jump when we can
        vector<int> a(n+2);

        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<vector<int>> psa(n+1, vector<int>(2,0));

        a[0] = -1e18;
        a[n+1] = 1e18;
        

        for(int i = 1; i <= n; i++){
            psa[i][1] = psa[i-1][1];
            psa[i][0] = psa[i-1][0];

            //cout << i << " " << a[i+1] - a[i] << " " << a[i] - a[i-1] << "\n";

            if(a[i+1] - a[i] < a[i] - a[i-1]){
                psa[i][1]++;
                psa[i][0] += (i != 1 ? a[i] - a[i-1] : a[i]);
            }
            else{
                psa[i][1] += a[i+1] - a[i];
                psa[i][0]++;
            }
        }

        //for(int i = 1; i <= n; i++) cout << psa[i][0] << " ";
        //cout << "\n";

        //1 + 1 + 4 + 8
        

        int q; cin >> q;

        while(q--){
            int l, r; cin >> l >> r;

            if(r > l) cout << psa[r-1][1] - psa[l-1][1] << "\n";
            else cout << psa[l][0] - psa[r][0] << "\n";
        }

    

        //closest will be either left or right
        //ans is the number of cities with same orientation + a[i] - a[j] of adjacent cities of different orientation

        //let right be positive and left negative 
    }
    
}

/*
try to solve a quickly
b go with your instinct instead of just sitting there
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/