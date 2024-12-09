#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<long long> a(n+2);

        for(int i = 1; i <= n; i++) cin >> a[i];

        long long ans = 1;

        for(int i = 1; i < n; i += 2) ans = max(ans, a[i+1] - a[i]);

        if(!(n&1)){
            cout << ans << "\n";
            continue;
        }   


        ans = 1e18;

        for(int i = 1; i <= n; i++){
            vector<long long> b = {0};

            for(int j = 1; j <= n; j++){
                if(j != i) b.push_back(a[j]);
            }

            long long tmp = 1;

            for(int i = 1; i < b.size(); i += 2) tmp = max(tmp, b[i+1] - b[i]);

            ans = min(ans, tmp);
        }

        cout << ans << "\n";
    }
}