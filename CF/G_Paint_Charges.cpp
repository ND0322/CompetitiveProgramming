#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int n, a[MAXN], dp[MAXN], st[MAXN<<2];

void build(int node, int l, int r){
    if(l == r){
        st[node] = a[l] - 
    }
}


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        

        for(int i = 1; i <= n; i++) cin >> a[i];

        if(n == 1){
            cout << "1\n";
            continue;
        }

        memset(dp,0,sizeof(dp));

        for(int i = n; i >= 1; i--){
            dp[i] = dp[min(n, i + a[i] -1)+1]+1;

            for(int j = i+1; j <= n; j++){
                if(j - a[j] < i) dp[i] = min(dp[i], dp[j+1]+1);
            }
        }

        cout << dp[1] << "\n";
    }
}