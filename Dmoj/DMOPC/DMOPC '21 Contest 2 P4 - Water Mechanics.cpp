#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;
const int INF = 1e9;

typedef pair<int,int> pii;


int n,k,a[MAXN],dp[MAXN],best[MAXN];
pii ranges[MAXN];



int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> a[i];

    
    ranges[0].first = 0;
    ranges[n-1].second = n-1;

    int cur = k;

    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]) cur--;
        else cur = k;

        if(a[i] == a[i-1] && cur <= 0) ranges[i].first = i-k;
        else if(a[i-1] <= a[i]) ranges[i].first = ranges[i-1].first;
        else ranges[i].first = i;
    }

    cur = k;

    for(int i = n-2; i >= 0; i--){
        if(a[i] == a[i+1]) cur--;
        else cur = k;

        if(a[i] == a[i+1] && cur <= 0) ranges[i].second = i+k;
        else if(a[i+1] <= a[i]) ranges[i].second = ranges[i+1].second;
        else ranges[i].second = i;
    }

    for(int i = 0; i < n; i++){
        best[ranges[i].first] = max(best[ranges[i].first],ranges[i].second);
    }

    for(int i = 1; i < n; i++) best[i] = max(best[i],best[i-1]);

  

    

    
    /*
    for(int i = 0; i < n; i++){
        cout << ranges[i].first << " " << ranges[i].second << "\n";
    }
    */
    
    
    
    

    

    

    fill(dp,dp+n,INF);
    dp[n] = 0;

    for(int i = n-1; i >= 0; i--){

        dp[i] = dp[best[i]+1] + 1;
       
        
    }

    cout << dp[0] << "\n";

    
    
}