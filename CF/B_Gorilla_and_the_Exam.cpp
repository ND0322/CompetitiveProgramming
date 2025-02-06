#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

#define int long long


//repeatitly apply on whole array
//do k by freq

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        map<int,int> freq;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            freq[x]++;
        }

        int ans = freq.size();

        vector<int> vals;

        for(pair<int,int> i : freq) vals.push_back(i.second);

        sort(vals.begin(), vals.end());

        for(int i : vals){
            if(k < i) break;
            ans--;
            k -= i;
        }

        cout << max(1LL, ans) << "\n";


    }
}