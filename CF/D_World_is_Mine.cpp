#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 5005;

int n, dp[MAXN][MAXN], a[MAXN];

map<int,int> mp;

//sort the array, a will always take smallest available
//dp[i] => answer at i
//transition by looping j which is the next blocked by b
//to be blocked freq[a[j]] <= dist

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        mp.clear();

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            mp[x]++;
        }

        n = mp.size();

        int j = 1;
        for(auto i : mp) a[j++] = i.second;

        for(int i = 0; i <= n+1; i++){
            for(int j = 0; j <= n+1; j++) dp[i][j] = 0;
        }

       
        for(int i = n; i >= 1; i--){
            for(int j = 0; j <= n; j++){
                //dont block
                dp[i][j] = dp[i+1][j+1];

                if(j >= a[i]) dp[i][j] = max(dp[i][j], dp[i+1][j-a[i]]+1);
            }
        }

        cout << n-dp[1][0] << "\n";
        
    }
}