#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(2*n+1);

        for(int i = 1; i <= 2*n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        vector<int> b = {0};

    

        for(int i = 1; i <= 2*n; i++){
            if(i == n) continue;
            b.push_back(a[i]);
        }

        int ans = abs(b[n] - a[n]);

        b = {0};

        for(int i = 1; i <= 2*n; i++){
            if(i == n+1) continue;
            b.push_back(a[i]);
        }

        ans = min(ans, abs(b[n] - a[n+1]));

        cout << ans << "\n";
    }
}