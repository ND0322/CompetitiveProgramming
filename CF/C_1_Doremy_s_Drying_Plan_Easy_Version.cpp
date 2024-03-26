#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>

using namespace std;

#define int long long


/*
1 2
1 2
1 1
*/




int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m,k; cin >> n >> m >> k;

        vector<int> l(n+5), r(n+5);

        vector<vector<int>> enter(n+5, vector<int>()), leave(n+5, vector<int>());
        vector<int> cnt(m+5);

        for(int i = 1; i <= m; i++){
            cin >> l[i] >> r[i];

            enter[l[i]].push_back(i);
            leave[r[i]+1].push_back(i);
            cnt[i] = 0;
        }

        set<int> cur;

        
        map<pair<int,int>,int> cnt2;

        cnt[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int x : enter[i]) cur.insert(x);
            for(int x: leave[i]) cur.erase(x);

            if(!cur.size()) cnt[0]++;
            if(cur.size() == 1)cnt[*cur.begin()]++;
            if(cur.size() == 2) cnt2[{*cur.begin(), *next(cur.begin())}]++;



        }

        int big = 0;
        int sec = 0;


        for(int i = 1; i <= m; i++){
            if(cnt[i] > big){
                sec = big;
                big = cnt[i];
            }
            else if(cnt[i] == big) sec = cnt[i];
        }

        int ans = cnt[0] + big + sec;

       for(pair<pair<int,int>,int> c:cnt2) ans = max(ans, cnt[0] + cnt[c.first.first] + cnt[c.first.second] + c.second);

       cout << ans << "\n";


        



    }
}