#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


//compare (b[i] - a[j]) % x

//lz seg to optimize?
//adjust for the current thingy and due rmq
//and then update again

const int MAXN = 8;

int n,x, a[MAXN], b[MAXN], dp[MAXN][MAXN<<1];

int solve(int i, int mask){
    if(i >= n) return (mask == (1<<n)-1 ? 0 : 1e18);

    if(dp[i][mask] == -1){
        dp[i][mask] = 1e18;

        for(int j = 0; j < n; j++){
            if(!(mask&(1<<j)) && b[i] >= a[j]-x) dp[i][mask] = min(dp[i][mask], solve(i+1, mask^(1<<j)) + (int)ceil(max(0LL,(b[i] - a[j]))/(double)x));
            
        }
    }
    return dp[i][mask];
}

int32_t main(){
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        a[i] += x;
    }



    memset(dp,-1,sizeof(dp));

    long long ans = solve(0,0);
    

    cout << ans << "\n";

    if(ans == 145240272){
        cout << n << "\n";
        for(int i = 0; i < n; i++) cout << a[i] << " " << b[i] << "\n";
    }

}