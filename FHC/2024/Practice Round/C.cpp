#include <bits/stdc++.h>
#include <iostream>
#include <random>
#include <ranges>
#include <map>

using namespace std;

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n; cin >> n;


        vector<pair<int,int>> a(n);

        int ans = 1e9;

        for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
        std::random_device rd;
        std::mt19937 eng(rd());

        std::shuffle(a.begin(), a.end(), eng);

        for(int i = 0; i < min(20, n); i++){
            map<double,int> mp;

            for(int j = 0; j < n; j++){
                if(j == i) continue;
                mp[(a[j].second - a[i].second)/(double)(a[j].first - a[i].first)]++;
            }

            for(auto j : mp){
                ans = min(ans, n-j.second-1);
            }
        }
 
        cout << "Case #" << _ << ": " << ans << "\n";
    }
}