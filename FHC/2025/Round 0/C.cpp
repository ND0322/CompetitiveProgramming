

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
obvious where the splits in arrays are

each thing can only be rotated up to m times

just do it greedily in reverse 

base of location of 1
*/

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<pair<int,int>> b;

        vector<pair<int,int>> ans;

        int sz = 0;
        int pos = 0;

        int i = 1; 

        for(int i = 1; i <= n; i++){
            if(sz && a[i] == 1){
                b.push_back({sz+1, a[i-1]});
                i += a[i-1] - sz - 1;
                sz = 0;
                pos = 0;
                continue;
            }
            else if(a[i] == 1) pos = -1;

            sz++;

            if(pos == -1 && a[i+1] != a[i]+1){
                b.push_back({1, sz});
                sz = 0;
                pos = 0;
                continue;
            }
            

           
        }

        if(sz) b.push_back({1, sz});


        vector<pair<int,int>> ops;
        int cnt = 0;

        for(int i= b.size()-1; i >= 0; i--){

            b[i].first = (b[i].first + cnt) % b[i].second;

            ops.push_back({b[i].second, (1 + b[i].second - b[i].first) % b[i].second});
            cnt += (1 + b[i].second - b[i].first) % b[i].second;
        }

        

        for(int i = ops.size()-1; i >= 0; i--){
            ans.push_back({1, ops[i].first});
            for(int j = 0; j < ops[i].second; j++) ans.push_back({2,0});
        }

        cout << "Case #" << _ << ": " << ans.size() << "\n";

        for(auto [x,y] : ans){
            if(x == 2) cout << 2 << "\n";
            else cout << x << " " << y << "\n";
        }
    }
}