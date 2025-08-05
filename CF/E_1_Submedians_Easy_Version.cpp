#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

/*
bsearch

maximum median value

number less than x >= r-l+2/2
*/

int n, a[MAXN], k;

pair<int,int> ans;

bool f(int x){
    vector<int> psa(n+2);

    for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + (a[i] >= x ? 1 : -1);


    int l = 0;
    for(int i = k; i <= n; i++){
        
        if(psa[i-k] < psa[l]) l = i-k;
            //i-k is new l

        if(psa[i] - psa[l] >= 0){
            ans = {l+1, i};
            return 1;
        }
    }

    return 0;

}
int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        

        for(int i = 1; i <= n; i++) cin >> a[i];

        int lo = 1;
        int hi = n;

        int best = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(f(mid)){
                lo = mid+1;
                best = mid;
            }
            else hi = mid-1;
        }

        cout << best << " " << ans.first << " " << ans.second << "\n"; 

        for(int i = 1; i <= n; i++) a[i] = 0;
    }
}