#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, k, dp[MAXN], orx[MAXN], ory[MAXN], rebuild[MAXN];

pair<pair<int,int>,int> a[MAXN];
pair<int,int> best[MAXN][2];


int depth(int i){
    if(i == 1) return 1;
    return depth(rebuild[i])+1;
}
void solve(int i){
    if(i != 1) solve(rebuild[i]);
    cout << orx[i] << " " << ory[i] << "\n";
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 0; i < MAXN; i++) best[i][0] = best[i][1] = {-1e9,-1e9};

    for(int i = 1; i <= n; i++){
        int x,y,c; cin >> x >> y >> c;

        orx[i] = x;
        ory[i] = y;

        a[i] = {{x,y}, i};
        dp[i] = c;

        if(i == 1){
            best[x][0] = {c, 1};
            best[y][1] = {c, 1};
        }
    }

    //im abt to go insane
    sort(a+1,a+n+1);


    bool flag = 1;
    for(int i = 1; i <= n; i++){
        if(a[i].second == 1){
            flag = 0;
            continue;
        }
        if(flag) continue;
        dp[a[i].second] += max(best[a[i].first.first][0].first, best[a[i].first.second][1].first) - k;
        if(max(best[a[i].first.first][0].first, best[a[i].first.second][1].first) < k) dp[a[i].second] = -1e9;
        rebuild[a[i].second] = max(best[a[i].first.first][0], best[a[i].first.second][1]).second;
        best[a[i].first.first][0] = max(best[a[i].first.first][0], {dp[a[i].second], a[i].second});
        best[a[i].first.second][1] = max(best[a[i].first.second][1], {dp[a[i].second], a[i].second});
    }

    cout << dp[n] << "\n";

    cout << depth(n) << "\n";
    solve(n);



}