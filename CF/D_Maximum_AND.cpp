#include <iostream>
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;



/*
consider bit by bit

Let a1 denote number of 1s and a and a0 be number of 0s

a1 = b0
a0 = b1

otherwise it is impossible for this bit to be set
Start from the highest valid bit

DAC
*/


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];


        vector<pair<vector<int>,vector<int>>> cur;

        cur.push_back({a,b});

        int ans = 0;

        for(int i = 29; i >= 0; i--){
            vector<pair<vector<int>,vector<int>>> nxt;

            bool flag = 1;
            for(auto j : cur){

                int cnt[2][2] = {{0,0},{0,0}};

                for(int k : j.first) cnt[0][(k>>i) & 1]++;
                for(int k : j.second) cnt[1][(k>>i) & 1]++;

                if(cnt[0][0] != cnt[1][1]){
                    flag = 0;
                    break;
                }

                nxt.push_back({});
                nxt.push_back({});
                

                for(int k : j.first) nxt[nxt.size()-1 - ((k>>i) & 1)].first.push_back(k);

                
                for(int k : j.second) nxt[nxt.size()-1 - !((k>>i) & 1)].second.push_back(k);

                
            }

            if(flag){
                cur = nxt;
                ans += 1<<i;
            }
            
        }

        cout << ans << "\n";


    }
}