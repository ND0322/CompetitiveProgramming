#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m,k; cin >> n >> m >> k;

        vector<bool> a(n+1);

        for(int i = 1; i <= n; i++){
            char c; cin >> c;


            a[i] = (c == '1');            
        }


        int cnt = 0;
        int i = 1;
        int ans = 0;

        for(; i <= n; i++){
            if(a[i]){
                cnt = 0;
                continue;
            }

            cnt++;

            if(cnt == m){
                //place first on this one
                i += k-1;
                cnt = 0;
                ans++;
            }
        }

        cout << ans << "\n";


    }
}