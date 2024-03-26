#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, dp[MAXN], rebuild[MAXN];

pair<int,int> a[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
        a[i].second = -a[i].second;
    }



    sort(a+1,a+n+1);

    for(int i = 1; i <= n; i++) a[i].second = -a[i].second;

    for(int i = n; i >= 1; i--){
        dp[i] = 1;
        for(int j = i+1; j <= n; j++){
            if(a[i].first <= a[j].first && a[i].second >= a[j].second){
                if(dp[j] + 1 > dp[i]){
                    rebuild[i] = j;
                    dp[i] = dp[j]+1;
                }
            }
        }
    }

    //cout << dp[1] << "\n";

    pair<int,int> ans = {-1,-1};

    for(int i = 1; i <= n; i++){
        ans = max(ans,{dp[i], i});
    }

    cout << ans.first << "\n";

    int cur = ans.second;

    while(cur){
        cout << a[cur].first << " " << a[cur].second << "\n";
        cur = rebuild[cur];
    }

    


}