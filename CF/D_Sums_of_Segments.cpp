#include <bits/stdc++.h>
#include <iostream>

//not hard to calculate what blocks are covered
//maybe sqrt 
//prefix sum of sum of all subarrays starting at i
//max of 2 subarrays will be partially covered 
//not hard to calculate the range that is covered 

const int MAXN = 3e5+5;

int a[MAXN], n, psa[MAXN], arrpsa[MAXN];

using namespace std;

//4 3 2 1


int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int q; cin >> q;

    while(q--){
        int l, r; cin >> l >> r;

        int lblock = 0;
        int rblock = n;

        int lo = 1;
        int hi = n;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(l > (n * (n+1))/2 - (mid * (mid+1))/2){
                hi = mid-1;
                lblock = n-mid+1;
            }
            else lo = mid+1;
        }

        lo = 1;
        hi = n;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(r > (n * (n+1))/2 - (mid * (mid+1))/2){
                hi = mid-1;
                rblock = n-mid+1;
            }
            else lo = mid+1;
        }

        //find position within the block
    }

}