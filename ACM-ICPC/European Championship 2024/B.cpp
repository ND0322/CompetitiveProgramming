#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, a[MAXN], b[MAXN];



int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i =1; i <= n; i++) cin >> b[i];

        sort(a+1, a+n+1);
        sort(b+1,b+n+1);
        reverse(b+1,b+n+1);

        int ans = 0;

        for(int k = 0; k <= n; k++){
            //k smallest with k largest

            int res = 1e9;

            for(int i = 1; i <= k; i++) res = min(res, abs(a[i] - b[k-i+1]));
            for(int i = k+1; i <= n; i++) res = min(res, abs(a[i] - b[k+n-i+1]));
            ans = max(ans, res);
        }

        cout << ans << "\n";

        
    }
}