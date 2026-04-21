#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
largest number with an inversion
take a subsequence 
*/


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];


        vector<pair<int,int>> suf(n+2);

        suf[n+1] = {-1, -(n+1)};

        for(int i = n; i >= 0; i--) suf[i] = max(suf[i+1], {a[i], -i});

        int i = 0;
        int last = 0;

        vector<int> nxt(n+1, -1);
        vector<pair<int,int>> seq;

        while(i != n+1){
            auto p = suf[i+1];
            if(p.first == -1) break;
            for(int j = last; j < -p.second; j++) nxt[j] = seq.size();
            last = -p.second+1;
            seq.push_back({p.first, -p.second});

            i = -p.second;
        }

        seq.push_back({-1e9, n+1});

        vector<int> ans;
        int skp = -1;

        for(int i = 1; i <= n; i++){
            if(nxt[i] == -1){
                if(i != skp) ans.push_back(a[i]);
                continue;
            }

            if(skp != -1) continue;

            if(a[i] >= seq[nxt[i]+1].first){
                skp = seq[nxt[i]].second;
                ans.push_back(seq[nxt[i]].first);

                vector<pair<int,int>> tmp(n+2);
                tmp[seq[nxt[i]].second] = {-1, -(seq[nxt[i]].second)};

                for(int j = seq[nxt[i]].second-1; j >= i; j--) tmp[j] = max(tmp[j+1], {a[j], -j});

                int j = i-1; 
                while(1){
                    auto p = tmp[j+1];

                    if(p.first == -1) break;
                    if(p.first >= seq[nxt[i]+1].first) ans.push_back(p.first);
                    j = -p.second;
                }


                
            }
        }

        for(int i = 0; i < ans.size()-1; i++) cout << ans[i] << " ";
        cout << ans.back() << "\n";

        

        
        

        




    }
}