#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int m, n; cin >> m >> n;

        vector<vector<int>> a(m+1, vector<int>(n+1));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++) cin >> a[i][j];
        }

        vector<pair<int,int>> mx(n+1);
        vector<vector<int>> cand(n+1);
        vector<int> cnt(m+1);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                mx[i] = max(mx[i], {a[j][i], j});
                if(a[j][i] == mx[i].first){
                    cand[i].push_back(j);
                    cnt[j]++;
                }
            }
        }



        set<int> s;

        int ans = 1e9;

        for(int i = 1; i <= n; i++){
            ans = min(ans, mx[i].first);
            s.insert(mx[i].second);
        }

        if(s.size() <= n-1){
            cout << ans << "\n";
            continue;
        }

        bool flag = 1;
        for(int i = 1; i <= n; i++){
            for(int j : cand[i]){
                cnt[j]--;
                if(cnt[j]){
                    flag = 1;
                    cout << ans << "\n";
                    break;
                }
            }

            if(flag) break;
        }

        if(flag) continue;

        
        
    }
}