#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4e5+5;

//split x and y and process seperately

#define int long long


int n, k, t[MAXN], a[MAXN][2];

bool can(int x, bool p){
    int last = t[0];

    int l = a[0][p] - x;
    int r = a[0][p];



    for(int i = 1; i < n; i++){
        
        int ti = t[i];

        l -= (ti - last) * k;
        r += (ti - last) * k;

       

        l = max(l, a[i][p] - x);
        r = min(r,a[i][p]);


        if(l > r) return 0;

        last = ti;
    }

    return 1;
}

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> t[i] >> a[i][0] >> a[i][1];

    int lo = 0;
    int hi = 1e9+10;
    int ans1 = -1;

    
    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid, 0)){
            ans1 = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    lo = 0;
    hi = 1e9+10;
    int ans = -1;


    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid, 1)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    


    

    //cout << can(3,0) << "\n";

    //cout << ans1 << " " << ans << "\n";

    cout << max(ans1,ans) << "\n";


    
    
}