#include <bits/stdc++.h>
#include <iostream>


using namespace std;


/*
obviously leave ci = 0 for last

greedily kill in increasing health with the smallest possible sword 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;

        multiset<int> s;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            s.insert(x);
        }


        vector<int> bad;

        vector<pair<int,int>> a;

        vector<int> b(m+1);
        vector<int> c(m+1);

        for(int i = 1; i <= m; i++) cin >> b[i];
        for(int i = 1; i <= m; i++) cin >> c[i];

        for(int i = 1; i <= m; i++){
            if(!c[i]) bad.push_back(b[i]);
            else a.push_back({b[i], -c[i]});
        }


        sort(a.begin(), a.end());
        sort(bad.begin(), bad.end());


        int cnt = 0;

        for(auto [p, q] : a){
            auto it = s.lower_bound(p);

            if(it == s.end()) continue;

            int val = max(*it, -q);

            s.erase(it);
            s.insert(val);
            cnt++;
        }

        for(int i : bad){
            if(s.empty()) break;
            auto it = s.lower_bound(i);

            if(it == s.end()) break;
            s.erase(it);
            cnt++;
        }

        cout << cnt << "\n";
        


    }
}