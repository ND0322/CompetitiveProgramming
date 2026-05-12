#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

//we can either move one or two steps 

int n, dp[MAXN];

bool a[MAXN][2];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        string s; cin >> s;

        for(int i = 0; i < n; i++) a[i+1][0] = (s[i] == 'R');
        cin >> s;

        for(int i = 0; i < n; i++) a[i+1][1] = (s[i] == 'R');

        dp[n+1] = 0;
        dp[n+2] = 0;
        

        for(int i = n; i >= 1; i--){
            dp[i] = dp[i+1] + (a[i][0] != a[i][1]);

            if(i != n) dp[i] = min(dp[i], dp[i+2] + (a[i][0] != a[i+1][0]) + (a[i][1] != a[i+1][1]));
        }

        cout << dp[1] << "\n";


    }
}