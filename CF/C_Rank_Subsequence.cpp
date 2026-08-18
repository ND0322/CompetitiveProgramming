#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> l(n+1);
        vector<int> r(n+1);
        vector<int> u(n+1);
        vector<int> v(n+1);
        

        for(int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> u[i] >> v[i];

        int ans = 0;
        for(int k = 0; k <= n; k++){

            int p = 1;
            int cnt = 0;
            for(int j = 1; j <= k; j++){
                while(1){
                    if(p == n+1) break;
                    if((j < l[p] || j > r[p]) && (j < k - v[p] + 1 || j > k - u[p] + 1)){
                        p++;
                        cnt++;
                        break;
                    }
                    p++;
                }
            }

            if(cnt != k) continue;
            ans = k;
        }

        cout << ans << "\n";

        /*
        let i be the jth element in subsequence of length k

        j < l || j > r
        k-j+1 < u || k-j+1 > v
        k - u + 1 < j || k-v+1 > j

        j < k-v+1 || j > k-u+1
        */
    }
}