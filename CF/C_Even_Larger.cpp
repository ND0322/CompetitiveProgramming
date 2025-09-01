#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
observation is that worst arrays are all length 2 because of the index
*/
int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i =1; i <= n; i++) cin >> a[i];

        long long ans = 0;
        for(int i = 2; i < n; i += 2){
            ans += max(a[i-1] + a[i+1] - a[i], 0);
            a[i+1] -= max(a[i-1] + a[i+1] - a[i], 0);
            a[i+1] = max(a[i+1], 0);
        }

        if(!(n&1)) ans += max(a[n-1] - a[n], 0);

        cout << ans << "\n";


    }
}