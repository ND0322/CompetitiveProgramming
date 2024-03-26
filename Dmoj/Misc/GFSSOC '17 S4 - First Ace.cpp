#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e4+5;

int n, dp[MAXN], tmp[MAXN];

pair<int,pair<int,int>> a[MAXN];


int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i].second.first >> a[i].second.second >> a[i].first;

    sort(a,a+n);



    for(int i = n-1; i >= 0; i--){
        for(int j = a[n-1].first; j >= 0; j--){
            tmp[j] = dp[j];

            if(j+a[i].second.second <= a[i].first) tmp[j] = max(tmp[j], dp[j+a[i].second.second] + a[i].second.first);
                
            
        }

        swap(tmp,dp);
    }

    cout << dp[0] << "\n";
}