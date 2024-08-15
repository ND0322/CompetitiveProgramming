#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

//number psa[r] - psa[l-1] = 0
//for each l use a map to count complement for psa[l-1]

int main(){
    int tt; cin >> tt;

    while(tt--){

        string s; cin >> s;

        int n = s.size();

        vector<int> psa(n+1);
        map<int, vector<int>> mp;

        for(int i = 1; i <= n; i++){
            psa[i] = psa[i-1] + pow(-1, s[i-1] == '0');
            mp[psa[i]].push_back(i);
        }

        long long ans = 0;

        for(auto i : mp){
            vector<int> a = i.second;

            long long sm = 0;

            int r = 0;

            for(int i = 0; i < a.size()-1; i++){
                while(r < a.size() - (lower_bound(a.begin(), a.end(), a[i]) - a.begin())){
                    sm += n - a[r];
                    r++;
                }

                ans += (a[i])
            }


        }


        cout << ans << "\n";
    }
}