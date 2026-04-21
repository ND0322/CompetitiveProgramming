#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 305;
const int MOD = 1e9+7;

int n, a[MAXN], A[20], B[20], dp[MAXN][20][20][3], l, r;

string lo, hi;

/*
number of ways to make l and r respectively 

dp is current pos, number of fronts we need, current length

when adding anything, we check that it matches length + number of fronts needed 

do it in reverse counting number of backs
*/

int solveA(int i, int front, int len, int small){
    if(front < 0) return 0;
    if(len == (int)lo.size() && small <= 1) return front == 0;
    if(i == r+1) return 0;

    if(dp[i][front][len][small] != -1) return dp[i][front][len][small];

    dp[i][front][len][small] = solveA(i+1, front, len, small);
    //add to back

    if(small == 0 || small == 2) dp[i][front][len][small] += solveA(i+1, front, len+1, small);
    else{
        if(A[len + front] > a[i]) dp[i][front][len][small] += solveA(i+1, front, len+1, 0);
        if(A[len+front] < a[i]) dp[i][front][len][small] += solveA(i+1, front, len+1, 2);
        if(a[len+front] == a[i]) dp[i][front][len][small] += solveA(i+1, front, len+1, 1);
    }

    //add to front 

    if(!front) return dp[i][front][len][small];

    if(A[front] < a[i]) dp[i][front][len][small] += solveA(i+1, front-1, len+1, 2);
    if(A[front] > a[i]) dp[i][front][len][small] += solveA(i+1, front-1, len+1, 0);
    if(A[front] == a[i]) dp[i][front][len][small] += solveA(i+1, front-1, len+1, small);
        

    return dp[i][front][len][small];
}

int solveB(int i, int front, int len, int small){
    if(front < 0) return 0;
    if(len > (int)hi.size()) return 0;
    if(i == r+1) return 0;

    cout << i << " " << front << " " << len << " " << small << "\n";

    if(dp[i][front][len][small] != -1) return dp[i][front][len][small];

    dp[i][front][len][small] = solveB(i+1, front, len, small);
    //add to back

    if(small == 0 || small == 2) dp[i][front][len][small] += solveB(i+1, front, len+1, small);
    else{
        if(B[len + front] > a[i]) dp[i][front][len][small] += solveB(i+1, front, len+1, 0);
        if(B[len+front] < a[i]) dp[i][front][len][small] += solveB(i+1, front, len+1, 2);
        if(B[len+front] == a[i]) dp[i][front][len][small] += solveB(i+1, front, len+1, 1);
    }

    //add to front 

    if(B[front] < a[i]) dp[i][front][len][small] += solveB(i+1, front-1, len+1, 2);
    if(B[front] > a[i]) dp[i][front][len][small] += solveB(i+1, front-1, len+1, 0);
    if(B[front] == a[i]) dp[i][front][len][small] += solveB(i+1, front-1, len+1, small);

    if(small <= 1 && front == 0) return front == 0;
        

    return dp[i][front][len][small];
}

int main(){
    cin >> n >> lo >> hi;

    for(int i = 0; i < lo.size(); i++) A[i] = lo[lo.size() - i - 1] - '0';
    for(int i = 0; i < hi.size(); i++) B[i] = hi[hi.size() - i - 1] - '0';

    for(int i = 1; i <= n ;i++) cin >> a[i];

    int q; cin >> q;

    while(q--){
        cin >> l >> r;

        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(int i = 0; i <= lo.size(); i++) ans -= solveA(l, i, 0, 1);

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i <= hi.size(); i++){
            ans += solveB(l, i, 0, 1);
            cout << solveB(l, i, 0, 1) << "\n";
        }


        
        
        cout << ans << "\n";

        
    }

    
}