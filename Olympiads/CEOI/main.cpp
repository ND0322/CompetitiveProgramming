#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n, m;

long long dp[2][MAXN*50];

pair<int,pair<int,pair<int,int>>> events[MAXN*2];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int a,b,c; cin >> a >> b >> c;

        events[i] = {b, {1, {a, c}}};
    }

    cin >> m;


    for(int i = n+1; i <= n+m; i++){
        int a,b,c; cin >> a >> b >> c;

        events[i] = {b, {0, {a, c}}};
    }

    int l = n+m;

    sort(events+1, events+l+1);

    for(int i = 1; i <= l; i++){
        for(int j = 0; j < MAXN * 50; j++){
            auto [t, p] = events[i].second;
            auto [cnt, cost] = p;

            dp[1][j] = dp[0][j];

            if(t == 0){
                //buy
                dp[1][j] = max(dp[1][j], dp[0][j+cnt] - cost);
            }
            else{
                //buy the query
                if(j >= cnt) dp[1][j] = max(dp[1][j], dp[0][j-cnt] + cost); 
            }
        }

        for(int j = 0; j < MAXN * 50; j++) dp[0][j] = dp[1][j];
        
    }

    cout << dp[1][0] << "\n";
}