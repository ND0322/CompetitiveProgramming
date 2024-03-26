#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1005;


int n,c,k;

long long dp[MAXN][20005];

pair<int,int>  vals[MAXN];
pair<pair<int,int>,int> stuffs[MAXN];



//sort items by cost


//case 1:
//iterate through all smallest costs and count the length of the longest prefix such that the sum is < cap
//if this length is <= k then the answer will be the sum of the k largest objects

//case 2:
//assign the first k items with the last k values
//using the left over capacity run knapsack on everything else






int main(){
    cin >> n >> c >> k;

    for(int i = 1; i <= n; i++){
        cin >> stuffs[i].first.first >> stuffs[i].first.second;
        stuffs[i].second = i;
    }

    sort(stuffs+1, stuffs+n+1);


    if(!k){
        for(int i = n; i >= 1; i--){
            for(int j = 0; j <= c; j++){
                dp[i][j] = dp[i+1][j];

                if(j - stuffs[i].first.first >= 0) dp[i][j] = max(dp[i][j], dp[i+1][j-stuffs[i].first.first] + stuffs[i].first.second);
            }
        }

        cout << dp[1][c] << "\n";
        return 0;
    }

    
    

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


    //calculating case 2:


    //dont recalc dp
    
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        vector<long long> big;
        int tot = 0;
        long long sum = 0;

        if(i < k) continue;

        for(int j = 1; j <= i; j++){
            big.push_back(stuffs[j].first.second);
            tot += stuffs[j].first.first;
        }

        if(tot > c) break;


        sort(big.begin(), big.end());
        for(int j = k; j < big.size(); j++) sum += big[j];

        
        memset(dp[i], 0, sizeof(dp[i]));
        for(int j = i+1; j <= n; j++){
            for(int l = 0; l <= c; l++){
                dp[j][l] = dp[j-1][l];

                if(l-stuffs[j].first.first >= 0) dp[j][l] = max(dp[j][l], dp[j-1][l-stuffs[j].first.first] + stuffs[j].first.second);
            }
        }

       

        for(int j = i+2; j <= n; j++){
            if(n-j < k) continue;
            big.clear();
            
            for(int l = n; l >= j; l--) big.push_back(stuffs[l].first.second);
            sort(big.rbegin(), big.rend());

            long long val = 0;
            for(int l = 0; l < k; l++) val += big[l];
            cout << i << " " << j << " " << sum << " " << val << " " << dp[j-1][c-tot] << " " << sum + dp[j-1][c-tot] + val << "\n";
            ans = max(ans, sum + dp[j-1][c-tot] + val);
        }

    }

    cout << ans << "\n";

}