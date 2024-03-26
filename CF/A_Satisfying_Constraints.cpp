#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        long long lo = 0;
        long long hi = 1e9;
        set<int> nums;

        for(int i = 0; i < n; i++){
            long long t,x; cin >> t >> x;

            if(t == 1) lo = max(lo, x);
            if(t == 2) hi = min(hi,x);
            if(t == 3) nums.insert(x);
        }

        long long ans = hi-lo+1;

        for(int i : nums){
            if(i >= lo && i <= hi) ans--;
        }

        cout << max(ans,0LL) << "\n";
    }
    
}