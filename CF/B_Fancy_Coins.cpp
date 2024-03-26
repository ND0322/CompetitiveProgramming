#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int m,k,a,b;

bool can(int x){
    
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> m >> k >> a >> b;

        int lo = 0;
        int hi = m;
        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)/2;

            if(can(mid)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        cout << ans << "\n";
    }

    
}