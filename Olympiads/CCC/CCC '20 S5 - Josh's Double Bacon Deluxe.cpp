#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//for each burger type, only the greatest index to want it matters
//lets say one of the non last ppl want some burger that was already taken
//they can just take from any of the rest of the burger type they want and they can always get it
//the last person to want it doesnt get it so they are the only one who make new probability

const int MAXN = 1e6+5;

int n, cnt[MAXN], a[MAXN];

double dp[MAXN];



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    int big = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        big = max(big,a[i]);
    }

    if(a[0] == a[n-1]){
        cout << "1\n";
        return 0;
    }
    cnt[a[0]] = cnt[a[n-1]] = 1;
    double tot = .5;

    dp[a[0]] = 1;
    dp[a[n-1]] = 0;

    for(int i = n-2; i > 0; i--){
        //this dude is the greatest index with that choice a[i]
        if(!cnt[a[i]]) dp[a[i]] = tot;
        cnt[a[i]]++;

        tot *= (n-i);
        tot += dp[a[i]];
        tot /= (n-i+1);
    }

    double ans = 0;

    for(int i = 1; i <= big; i++) ans += (dp[i] * cnt[i])/n;
    cout << setprecision(6) << fixed << ans << "\n";




}