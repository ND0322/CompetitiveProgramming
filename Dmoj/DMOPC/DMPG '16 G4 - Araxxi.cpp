#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,m,a[MAXN],d[MAXN],dp[MAXN];

//dp[i] = min (i < j < n) dp[j+d[a[i]]] + d + (j-i)-cnt[a[i]]

//cnt can be calculated with ost

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> d[i];

    for(int i = n-1; i >= 0; i--){
       
    }


}