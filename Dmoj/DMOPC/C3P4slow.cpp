#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 205;

int n,c,k;

long long dp[205][20005][7];

pair<int,int>  vals[MAXN];
pair<pair<int,int>,int> stuffs[MAXN];

//sort by cost break ties by largest val cause the greedy sh fails 
int main(){
    cin >> n >> c >> k;

    for(int i = 1; i <= n; i++){
        cin >> stuffs[i].first.first >> stuffs[i].first.second;
        stuffs[i].second = i;
    }

    sort(stuffs+1, stuffs+n+1);
    

    for(int i = 1; i <= n; i++){
        vals[i].first = stuffs[i].first.second;
        vals[i].second = i;
    }
    sort(vals+1, vals+n+1);
    reverse(vals+1, vals+n+1);

    

    
 
    //checking case 1
    int check = 0;
    int ind = -1;
    for(int i = 1; i <= n; i++){
        check += stuffs[i].first.first;
        if(check > c) break;
        ind = i;
    }

    ind++;

    

    long long tot = 0;
    int cnt = 0;

   

    
    

    for(int i = 1; i < ind; i++){
        tot += vals[i].first;  
        if(vals[i].second >= ind) cnt++;
    }

    

    if(cnt <= k){
        cout << tot << "\n";
        return 0;
    }

    sort(stuffs+1, stuffs+n+1);

    for(int i = 0; i <= c; i++){
        for(int j = 1; j <= k; j++) dp[0][i][j] = -1e18;
    }

    for(int i =1; i <= n; i++){
        for(int j = 0; j <= c; j++){
            for(int l = 0; l <= k; l++){
                dp[i][j][l] = dp[i-1][j][l];

                if(j - stuffs[i].first.first >= 0){
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-stuffs[i].first.first][l] + stuffs[i].first.second);
                    if(l) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-stuffs[i].first.first][l-1]);
                       

                }
            }
        }
    }




    long long ans = 0;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= k; j++){
            vector<int> cur;

            for(int l = n; l > i; l--) cur.push_back(stuffs[l].first.second);
            if(cur.size() < j) break;
            sort(cur.rbegin(), cur.rend());

            long long tot = 0;
            for(int l = 0; l < j; l++) tot += cur[l];
            ans = max(ans, dp[i][c][j] + tot);
        }
    }

    cout << "1\n";

    cout << ans << "\n";
}