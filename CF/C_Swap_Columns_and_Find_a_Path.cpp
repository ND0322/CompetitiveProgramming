#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i <= n ; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
            
        int ans = -1e9;

        for(int i = 1; i <= n; i++){
            int res = 0;

            res = a[i] + b[i];

            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                res += max(a[j], b[j]);
            }


            ans = max(ans, res);
        }

        cout << ans << "\n";
        
    }
}

//we can switch rows at most once
//sort by a[0] - a[1] and we choose one that has maximum a[0] + a[1]
//we just fix the a[0] + a[1] cause n is small
