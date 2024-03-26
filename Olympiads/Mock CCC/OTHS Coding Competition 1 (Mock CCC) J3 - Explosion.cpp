#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, d, a[MAXN];

int main(){
    cin >> n >> d;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    int best = 0;

    int i = 1;

    while(i <= n){
        
        ans++;

        int cnt = 1;

        while(i < n && abs(a[i] - a[i+1]) <= d){
        
            cnt++;
            i++;
        }
        i++;

        best = max(best,cnt);
    }

    cout << ans << "\n";
    cout << best << "\n";
}