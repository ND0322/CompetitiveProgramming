#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,q; cin >> n >> q;

        vector<bool> covered(n+1);
        vector<bool> bad(n+1);

        vector<pair<int,int>> ranges;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            if(i < x) ranges.push_back({x-1, i});
            else ranges.push_back({i, x+1});
        }

        sort(ranges.begin(), ranges.end());

        int i = 1;

        for(auto [r,l] : ranges){
            i = max(i, l);
            while(i <= r) covered[i++]=1;
        }

        vector<bool> s(n+1);

        for(int i = 1; i <= n; i++){
            char c; cin >> c;

            s[i] = (c == 'R');
        }



        set<int> bads;

        for(int i = 1; i < n; i++){
            if(covered[i] && !s[i] && s[i+1]){
                bad[i] = 1;
                bads.insert(i);
            }
        }

        while(q--){
            int i; cin >> i;



            s[i] = 1-s[i];

            if(bad[i]){
                bad[i] = 0;
                bads.erase(i);
            }
            else if(i != n && covered[i] && !s[i] && s[i+1]){
                bad[i] = 1;
                bads.insert(i);
            }

            if(i != 1 && bad[i-1]){
                bad[i-1] = 0;
                bads.erase(i-1);
            }

            if(i != 1 && covered[i-1] && !s[i-1] && s[i]){
                bad[i-1] = 1;
                bads.insert(i-1);
            }

            cout << ((bool)bads.size() ? "NO\n" : "YES\n");


        }
        
        
    }
}