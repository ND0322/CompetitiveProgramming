#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int l = 0;
        int r = n-1;

        int lb = 0;
        int rb = m-1;

        long long ans = 0;

        while(l <= r){
            if(abs(a[l] - b[rb]) <= abs(a[r] - b[lb])){
                ans += abs(a[r] - b[lb]);
                r--;
                lb++;
            }
            else{
                ans += abs(a[l] - b[rb]);
                l++;
                rb--;
            }
        }

        cout << ans << "\n";
    }
}