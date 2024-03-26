#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//pretty easy just checking subarray sum and check that it can get started
//cant all be the same use the abs gap method

#define int long long

const int MAXN = 3e5+5;

int n, a[MAXN], psa[MAXN], dif[MAXN];

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        //1 1 2 1 2
        //0 0 1 1 2

        for(int i = 0; i <= n+1; i++){
            a[i] = 0;
            psa[i] = 0;
            dif[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            cin >> a[i];

            psa[i] += psa[i-1] + a[i];
        }

        for(int i = 2; i <= n; i++) dif[i] += dif[i-1] + abs(a[i] - a[i-1]);

        for(int i = 1; i <= n; i++){
            //bsearch for rightmost l that works

            if(a[i-1] > a[i] || a[i] < a[i+1]){
                cout << "1 ";
                continue;
            }
            
            int lo = 1;
            int hi = i-2;

            int ans = 1e9;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(psa[i-1] - psa[mid-1] > a[i] && (dif[i-1] - dif[mid-1])){
                    ans = i-mid;
                    lo = mid+1;
                }
                else hi = mid-1;
            }

            lo = i+2;
            hi = n;

            int res = 1e9;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(psa[mid] - psa[i] > a[i] && (dif[mid] - dif[i])){
                    res = mid-i;
                    hi = mid-1;
                }
                else lo = mid+1;
            }

            cout << (min(ans,res) == 1e9 ? -1 : min(ans,res)) << " ";
       
        }

        cout << "\n";
    }
}