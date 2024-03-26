#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        map<int,int> cnt;
        int ans = 0;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;            
            if(!cnt[x]){
                ans++;
                cnt[x ^ ((1LL<<31)-1LL)]++;
            }
            else cnt[x]--;
        }

        cout << ans << "\n";
    }
}
