#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n;

long long dp[MAXN], a[MAXN];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    dp[0] = a[0]/3;
    long long sum = a[0];

    for(int i = 1; i < n; i++){
        long long cnt = min(sum - 3 * dp[i-1], a[i]/2);
        //make isosceles triangles with leftovers plus two of these
        //make equilateral with remaining 
        dp[i] = dp[i-1] + cnt + (a[i] - cnt*2)/3;
        sum += a[i];
    }

    cout << dp[n-1] << "\n";
}   