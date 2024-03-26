#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        map<int,vector<int>> m;

        int n,x,y; cin >> n >> x >> y;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++){
            cin >> a[i];

            m[a[i] % y].push_back(a[i]);
        }

        long long ans = 0;

        for(auto i : m){
            map<long long, long long> cnt;

            for(int j : i.second){
                if(cnt.count(j%x)) ans += cnt[j%x];
                cnt[(x - (j%x)) % x]++;
            }
        }

        cout << ans << "\n";
    }

}