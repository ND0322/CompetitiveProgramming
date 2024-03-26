#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 11;
const int INF = 1e9;

int l, r, w, a[MAXN], b[MAXN], dp[1<<MAXN][1<<MAXN][2];


int solve(int ml, int mr, bool side, int sl, int sr){
    if(abs(sl-sr) > w) return INF;
    if(!ml && !mr) return 0;
    
    if(dp[ml][mr][side] == -1){
        dp[ml][mr][side] = INF;

        for(int i = 0; i < l; i++){
            if(ml & (1<<i)) dp[ml][mr][side] = min(dp[ml][mr][side], solve(ml ^ (1<<i), mr, 0, sl-a[i], sr) + (side != 0));
        }

        for(int i = 0; i < r; i++){
            if(mr & (1<<i)) dp[ml][mr][side] = min(dp[ml][mr][side], solve(ml, mr ^ (1<<i), 1, sl, sr - b[i]) + (side != 1));
        }

    }
    return dp[ml][mr][side];
    
}
int main(){
    cin >> l >> r >> w;

    int sl = 0, sr = 0;

    for(int i = 0; i < l; i++){
        cin >> a[i];
        sl += a[i];
    }
    for(int i = 0; i < r; i++){
        cin >> b[i];
        sr += b[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << min(solve((1<<l)-1, (1<<r)-1, 0, sl, sr), solve((1<<l)-1, (1<<r)-1, 1, sl, sr))+1 << "\n";





    
}