#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
only sqrt n options we can take
for each option bsearch on the next good thing
2p also good work 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1), dp(n+2), r(n+1), sm(n+1);

        vector<vector<int>> pos(n+1, vector<int> (1));

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = n; i >= 1; i--) pos[a[i]].push_back(i);
            
        
        
        for(int i = n; i >= 1; i--){
            sm[a[i]]++;
            if(sm[a[i]] >= a[i]) r[a[i]]++;

            dp[i] = dp[i+1];
        

            if(pos[a[i]][r[a[i]]]) dp[i] = max(dp[i], dp[pos[a[i]][r[a[i]]]+1] + a[i]);            
        }

        cout << dp[1] << "\n";
    }


}