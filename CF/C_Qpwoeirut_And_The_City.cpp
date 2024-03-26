#include <bits/stdc++.h>
#include <iostream> 

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        long long ans = 0;

        for(int i = 2; i < n; i+=2) ans += max(max(a[i-1], a[i+1]) - a[i] + 1,0);

        if(n&1){
            cout << ans << "\n";
            continue;
        }

        long long res = 0;

        for(int i = 3; i < n; i+=2) res += max(max(a[i-1], a[i+1]) - a[i] + 1,0);

        cout << min(ans,res) << "\n";

    }
}