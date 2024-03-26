#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,q;

long long psa[MAXN];

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    while(q--){
        string whytfisthishere; cin >> whytfisthishere;

        int l,x; cin >> l >> x;

        int lo = 1;
        int hi = n;
        int ans= -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(psa[mid] - psa[l-1] >= x){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        cout << (ans == -1 ? n : ans) << "\n";

    }
}