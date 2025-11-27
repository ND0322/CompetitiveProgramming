#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, q; cin >> n >> q;
        

        vector<int> a(n+1);

        vector<int> ans(q+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<pair<pair<int,int>,int>> queries = {{{0,0}, 0}};

        for(int i = 1; i <= q; i++){
            int l,r; cin >> l >> r;
            r -= 2;
            if(r >= 1) queries.push_back({{l,r}, i});
            else ans[i] = 1;
            
        }

        sort(queries.begin(), queries.end());

        if(queries.size() < 2){
            for(int i = 1; i <= q; i++) cout << (ans[i] ? "YES\n" : "NO\n");
            continue;
        }


        int cnt = 0;


        int l = queries[1].first.first;
        int r = l;


        for(int i = 1; i < queries.size(); i++){

        

            while(r <= queries[i].first.second){
                cnt += (a[r] > a[r+1] && a[r+1] > a[r+2]) + (a[r] > a[r+2] && a[r+1] > a[r]);
                r++;
            }

            while(l < queries[i].first.first){
                cnt -= (a[l] > a[l+1] && a[l+1] > a[l+2]) + (a[l] > a[l+2] && a[l+1] > a[l]);
                l++;
            }


            ans[queries[i].second] = !cnt;
        }

        
        for(int i = 1; i <= q; i++) cout << (ans[i] ? "YES\n" : "NO\n");
       

    


    }
}