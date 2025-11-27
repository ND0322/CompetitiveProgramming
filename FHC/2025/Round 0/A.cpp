#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n; cin >> n;

        vector<set<int>> s(n+1);
        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s[a[i]].insert(i);
        }
        for(int i = 1; i <= n; i++) cin >> b[i];

        bool flag = 1;
        vector<pair<int,int>> ans;
        for(int i = 1; i <= n; i++){
            for(int j : s[i]){
                if(!s[b[j]].size() || b[j] < i){
                    flag = 0;
                    break;
                }

                if(b[j] == i) continue;

                ans.push_back({j, *s[b[j]].begin()});
            }
        }

        cout << "Case #" << _ << ": ";
        if(!flag){
            cout << "-1\n";
            continue;
        }

       
        cout << ans.size() << "\n";

        for(auto [x,y] : ans) cout << y << " " << x << "\n";

        

        
    }
}