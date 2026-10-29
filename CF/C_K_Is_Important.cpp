#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
2k-1 >= m
Choose middle subarray

for remaining case its a bit different 
take sum - minimum subarray
*/


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> a(n+1);
        for(int i = 1; i <= n ;i++) cin >> a[i];

        vector<int> b = {0};

        int ans = 0;
        int sm = 0;
        for(int i = 1; i <= n; i++){
            if(k <= i && i <= n-k+1) ans += a[i];
            else{
                b.push_back(a[i]);
                sm += a[i];
            }
        }
                
        
        vector<int> psa(b.size());


        for(int i = 1; i < b.size(); i++) psa[i] = psa[i-1] + b[i];

        //size is k-1

        int mn = 1e9;
        for(int i = 1; i < b.size()-k+2; i++){

            mn = min(mn, psa[i+k-2] - psa[i-1]);
        }

        cout << ans + sm - mn << "\n";
    }
}