#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n, k;

long long a[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        for(int i = 1; i <= n; i++) cin >> a[i];

        if(k >= 3){
            cout << "0\n";
            continue;
        }

        
        sort(a+1, a+n+1);
        //cout << n << "\n";
        //for(int i = 1; i <= n; i++) cout << a[i] << " ";
        //cout << "\n";

        long long ans = a[1];
        for(int i = 1; i < n; i++) ans = min(ans, a[i+1] - a[i]);
        
        if(k == 1){
            cout << ans << "\n";
            continue;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                long long cur = abs(a[i] - a[j]);

                auto it = lower_bound(a + 1, a + 1 + n, cur) - a;
                ans = min(ans, a[it] - cur);
                if (it != 1) ans = min(ans, cur - a[--it]);
            
            }
        }

        cout << ans << "\n";
            


    }




}