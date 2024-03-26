#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, k,psa[MAXN],h[MAXN],best[MAXN];


bool can(int x){
    for(int i = 0; i + x <= n; i++){
        if(best[i] < x) continue;

        if(psa[i+x] - psa[i] <= k) return true;
    }

    return false;
}

int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

       

        for(int i = 0; i < n; i++){
            int x; cin >> x;


            psa[i+1] = psa[i] + x;
        }

        for(int i = 0; i < n; i++) cin >> h[i];


        //dp
        best[n-1] = 1;

        for(int i = n-2; i >= 0; i--){
            if(!(h[i] % h[i+1])) best[i] = best[i+1] + 1;
            else best[i] = 1;
        }

        int lo = 1;
        int hi = 2e5+5;
        

        while(lo <= hi){
            int mid = (lo+hi)/2;

            if(can(mid)){
                
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        cout << hi << "\n";





    }
    
}