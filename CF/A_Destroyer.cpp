#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int cnt[105];
set<int> nums;

void solve(){
    fill(cnt,cnt+104,0);
    nums.clear();
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        cnt[x]++;
        nums.insert(x);

    }

    for(int i: nums){
        if(!i) continue;

        if(cnt[i] > cnt[i-1]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
    }

}