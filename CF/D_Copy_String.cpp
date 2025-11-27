#include <bits/stdc++.h>
#include <iostream>

using namespace std;

set<int> pos[30];

//go from right to left and calculate the maximum right bound 

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        for(int i = 0 ; i < 26;i ++) pos[i].clear();

        string s; cin >> s;
        string t; cin >> t;

        for(int i = 0; i < n; i++) pos[s[i] - 'a'].insert(i);

        string tmp = "";

        for(int i = 0; i < n; i++) tmp += '.';
        vector<string> dp(k+1,tmp);
        dp[0] = s;

        int r = n;

        for(int i = n-1; i >= 0; i--){
            if(pos[t[i] - 'a'].empty()) continue;
            auto it = pos[t[i] - 'a'].lower_bound(min(i, r)+1);
            if(it == pos[t[i] - 'a'].begin()) continue;
            it--;

            for(int j = i - *it; j <= k; j++) dp[j][i] = t[i];
            for(int j = 1; j < i - *it && j <= k; j++) dp[j][*it+j] = t[i];
            r = *it;
            
        }

        for(int i = 1; i <= k; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] == '.') dp[i][j] = dp[i-1][j];
            }
        }

        int ind = -1;
        for(int i = 0; i <= k; i++){
            if(dp[i] == t){
                cout << i << "\n";
                ind = i;
                break;
            }
        }

        if(ind == -1){
            cout << "-1\n";
            continue;
        }

        for(int i = 1; i <= ind; i++) cout << dp[i] << "\n";

        



        
    }
}