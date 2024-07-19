#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN], cur[25], fir[25];

bool can(int x){
    memset(cur, 0, sizeof(cur));
    memset(fir, 0, sizeof(fir));
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < 20; j++){
            if(a[i] & (1<<j)){
                cur[j]++;
                fir[j]++;
            }
        }
    }

    for(int i = x+1; i <= n; i++){
        for(int j = 0; j < 20; j++){
            if(a[i-x] & (1<<j)) cur[j]--;
            if(a[i] & (1<<j)) cur[j]++;
        }

        for(int j = 0; j < 20; j++){
            if((bool)fir[j] != (bool)cur[j]) return 0;
        }
    }

    return 1;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];


        int lo = 1;
        int hi = n;
        int ans = n;



        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(can(mid)){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }

        cout << ans << "\n";


    }
}