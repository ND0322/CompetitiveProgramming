#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        long long k; cin >> k;

        long long ans = 0;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin()+1, a.end());

        int r = 1;
        long long sm = 0;

        for(int i = 1; i <= n; i++){
            while(r <= n && a[r] - a[i] <= 1 && sm + a[r] <= k){
                sm += a[r];
                r++;
            }

            ans = max(ans, sm);

            sm -= a[i];
        } 


        cout << ans << "\n";
    }
}