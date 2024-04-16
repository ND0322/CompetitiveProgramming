#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>

using namespace std;

const int MAXN = 1e4+5;

int n, k, a[MAXN];

set<double> dp[MAXN];

//runtimes probably nk
//couldnt do this prob before cause i thought 10000^2 doesnt pass

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[n+1].insert(0);

    for(int i = n; i >= 1; i--){
        //no small to large cause the dp gonna get reused
        for(double x : dp[i+1]) dp[i].insert(x+a[i]);
        if(i+2 <= n+1) for(double x : dp[i+2]) dp[i].insert(x + a[i] + a[i+1] - min(a[i], a[i+1])/2.0);
        if(i+3 <= n+1) for(double x : dp[i+3]) dp[i].insert(x + a[i] + a[i+1] + a[i+2] - min({a[i], a[i+1], a[i+2]}));
        while((int)dp[i].size() > k) dp[i].erase(prev(dp[i].end()));
        cout << i << "\n";
        for(int x : dp[i]) cout << x << " ";
        cout << "\n";
    }

    if((int)dp[1].size() != k){
        cout << "-1\n";
        return 0;
    }

    cout << setprecision(1) << fixed << *dp[1].rbegin() << "\n";


}