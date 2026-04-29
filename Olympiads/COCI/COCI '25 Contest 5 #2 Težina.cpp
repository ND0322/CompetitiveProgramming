#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MX = 1e8;



/*
floor(ai / j) * (ai + 2) for each j from [1:k]

for each a there is sqrt big value and sqrt small values

big values come from dividing by [1:sqrt(x)]
small values are directly [1:sqrtx]



*/


int32_t main(){
    int n,k; cin >> n >> k;


    vector<int> a(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(k, (int)sqrt(a[i])); j++){
            int v = (a[i] / j) * (a[i] + 2);
            ans += min(MX, v);

        }   

   

        for(int j = 1; j <= sqrt(a[i]); j++){
            //small values come from dividing by certain k

            int r = a[i] / j;
            int l = max(a[i] / (j+1) + 1, (int)sqrt(a[i])+1);

           
            if(k < l) continue;
            r = min(r, k);
            if(r < l) continue;
            
            int v = min(j * (a[i] + 2), MX);
            ans += (r - l + 1) * v;
    

            
        }

    }

    cout << ans << "\n";
}





