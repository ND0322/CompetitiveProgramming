#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;


int n,m, l;

bool reset[MAXN];

/*
bsearch

use upgrade k+1 things and distribute evenly 
*/


bool f(int x){
    //some number of zeros, one in between and some number of x

    int zeros = m-1;

    int cur = 0;

    int done = 0;

    for(int i = 1; i <= l; i++){
        if(zeros != -1) cur++;

        //cout <<zeros << " " << cur << " " << done << "\n";
        if(cur == x){
            cur = 0;
            zeros--;
            done++;
        }

        if(reset[i]){
            if(done){
                done--;
                zeros++;
            }
            else cur = 0;
        } 
    }

    return done;
}
int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m >> l;

        for(int i = 1; i <= l; i++) reset[i] = 0;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            reset[x] = 1;
        }

        int lo = 0;
        int hi = l;

        int ans = 0;


        
         while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(f(mid)){
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }

        cout << ans << "\n";
        
        
        
       

        


    }
}