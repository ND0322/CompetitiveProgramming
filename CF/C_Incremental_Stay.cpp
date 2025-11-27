#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
subarrays of size 2k

amortizes to n log n

subsequence with distance between to things <= k

max and min subsequence 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<long long> psa(2*1);
        vector<int> a(2*n+1);

        vector<long long> ans(n+1);
        for(int i = 1; i <= 2*n; i++) cin >> a[i];
        for(int i = 1; i <= 2*n; i++) psa[i] = psa[i-1] + a[i];

        vector<int> tmp;
        for(int i = 1; i <= 2 *n; i += 2) tmp.push_back(psa[i+1] - psa[i-1]);

        int sm = 0;

        for(int i = 0; i < tmp.size(); i += 2) sm -= tmp[i];
        for(int i = 1; i < tmp.size(); i += 2) sm += tmp[i];

        cout << sm << "\n";
        

        for(int k = 1; k <= n; k++){
            bool p = 1;
            for(int i = 1; i <= 2*n; i += k){
                ans[k] += pow(-1, p) * (psa[i+k-1] - psa[i-1]);
                p ^= 1;
            }
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}