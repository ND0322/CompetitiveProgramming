#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long



/*
dp

dp -> max r from here

if a[i] == b[i] we want to transition to the next of either a[j] or b[j] = a[i]+1


*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> b(n+1);

        vector<int> dp(n+5);
        set<int> pos;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] == 1) pos.insert(i);
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
            if(b[i] == 1) pos.insert(i);
        }

        vector<int> nxt(n+5);

        for(int i = n; i >= 1; i--){
            

            if(a[i] == b[i]){
                if(!nxt[a[i]+1]) dp[i] = n+1;
                else if(a[nxt[a[i]+1]] != b[nxt[a[i]+1]]) dp[i] = nxt[a[i]+1];
                else dp[i] = dp[nxt[a[i]+1]];

            }

            nxt[a[i]] = i;
            nxt[b[i]] = i;
            
            
        }

        //search for the next 1. If it is a double we can use the dp value 


        int ans = 0;
        for(int i = 1; i <= n; i++){
            auto it = pos.lower_bound(i);


            if(it == pos.end()){
                ans += n+1-i;
                continue;
            }



            if(a[*it] == b[*it]){
                ans += dp[*it] - i;

                continue;
            }

            ans += *it - i;
        }

        cout << ans << "\n";



    }
}